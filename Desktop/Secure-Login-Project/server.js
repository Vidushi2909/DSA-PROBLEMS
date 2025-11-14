// Import required packages
const express = require('express');
const bcrypt = require('bcrypt');
const sqlite3 = require('sqlite3').verbose();
const session = require('express-session');
const path = require('path');

// Create Express app (this is our server)
const app = express();
const PORT = 3000;

// Middleware - allows server to read form data
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Serve static files (HTML, CSS, JS files)
app.use(express.static(__dirname));

// Session management - keeps users logged in
app.use(session({
    secret: 'your-secret-key-change-this',
    resave: false,
    saveUninitialized: false,
    cookie: { secure: false } // Set to true if using HTTPS
}));

// Create/Connect to SQLite database
const db = new sqlite3.Database('./users.db', (err) => {
    if (err) {
        console.error('Database connection error:', err);
    } else {
        console.log('Connected to SQLite database');
    }
});

// Create users table if it doesn't exist
db.run(`CREATE TABLE IF NOT EXISTS users (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    username TEXT NOT NULL,
    email TEXT UNIQUE NOT NULL,
    password TEXT NOT NULL,
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
)`);

// SIGNUP API - Handles user registration
app.post('/api/signup', async (req, res) => {
    try {
        const { username, email, password } = req.body;
        
        // Server-side validation
        if (!username || username.length < 3) {
            return res.json({ success: false, message: 'Username must be at least 3 characters' });
        }
        
        if (!email || !email.includes('@')) {
            return res.json({ success: false, message: 'Invalid email format' });
        }
        
        if (!password || password.length < 6) {
            return res.json({ success: false, message: 'Password must be at least 6 characters' });
        }
        
        // Check if user already exists
        db.get('SELECT * FROM users WHERE email = ?', [email], async (err, user) => {
            if (err) {
                return res.json({ success: false, message: 'Database error' });
            }
            
            if (user) {
                return res.json({ success: false, message: 'Email already registered' });
            }
            
            // Hash the password (SECURITY FEATURE #1: Password Hashing)
            const hashedPassword = await bcrypt.hash(password, 10);
            
            // Insert user into database (SECURITY FEATURE #2: SQL Injection Prevention - using prepared statements)
            db.run('INSERT INTO users (username, email, password) VALUES (?, ?, ?)', 
                [username, email, hashedPassword], 
                function(err) {
                    if (err) {
                        return res.json({ success: false, message: 'Error creating account' });
                    }
                    
                    res.json({ success: true, message: 'Account created successfully!' });
                }
            );
        });
        
    } catch (error) {
        res.json({ success: false, message: 'Server error' });
    }
});

// LOGIN API - Handles user authentication
app.post('/api/login', async (req, res) => {
    try {
        const { email, password } = req.body;
        
        // Validation
        if (!email || !password) {
            return res.json({ success: false, message: 'Email and password required' });
        }
        
        // Find user in database
        db.get('SELECT * FROM users WHERE email = ?', [email], async (err, user) => {
            if (err) {
                return res.json({ success: false, message: 'Database error' });
            }
            
            if (!user) {
                return res.json({ success: false, message: 'Invalid email or password' });
            }
            
            // Compare password with hashed password (SECURITY FEATURE: Password verification)
            const passwordMatch = await bcrypt.compare(password, user.password);
            
            if (!passwordMatch) {
                return res.json({ success: false, message: 'Invalid email or password' });
            }
            
            // Create session (SECURITY FEATURE #5: Session Management)
            req.session.userId = user.id;
            req.session.username = user.username;
            req.session.email = user.email;
            
            res.json({ 
                success: true, 
                message: 'Login successful!',
                user: { username: user.username, email: user.email }
            });
        });
        
    } catch (error) {
        res.json({ success: false, message: 'Server error' });
    }
});

// Check if user is logged in
app.get('/api/check-session', (req, res) => {
    if (req.session.userId) {
        res.json({ 
            loggedIn: true, 
            user: { 
                username: req.session.username,
                email: req.session.email
            }
        });
    } else {
        res.json({ loggedIn: false });
    }
});

// Logout API
app.post('/api/logout', (req, res) => {
    req.session.destroy((err) => {
        if (err) {
            return res.json({ success: false, message: 'Logout failed' });
        }
        res.json({ success: true, message: 'Logged out successfully' });
    });
});
// Start the server
app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
