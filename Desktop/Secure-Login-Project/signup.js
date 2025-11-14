document.addEventListener('DOMContentLoaded', function() {
    
    const form = document.getElementById('signupForm');
    
    form.addEventListener('submit', async function(event) {
        event.preventDefault();
        
        const username = document.getElementById('username').value;
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;
        const confirmPassword = document.getElementById('confirmPassword').value;
        
        // Client-side validation (SECURITY FEATURE #3: Input Validation)
        if (!validateForm(username, email, password, confirmPassword)) {
            return;
        }
        
        // Sanitize inputs (SECURITY FEATURE #4: XSS Prevention)
        const sanitizedUsername = sanitizeInput(username);
        const sanitizedEmail = sanitizeInput(email);
        
        // Send data to server
        try {
            const response = await fetch('/api/signup', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    username: sanitizedUsername,
                    email: sanitizedEmail,
                    password: password
                })
            });
            
            const data = await response.json();
            const messageElement = document.getElementById('message');
            
            if (data.success) {
                messageElement.textContent = data.message;
                messageElement.style.color = 'green';
                
                // Redirect to login page after 2 seconds
                setTimeout(() => {
                    window.location.href = 'login.html';
                }, 2000);
            } else {
                messageElement.textContent = data.message;
                messageElement.style.color = 'red';
            }
            
        } catch (error) {
            document.getElementById('message').textContent = 'Error connecting to server';
            document.getElementById('message').style.color = 'red';
        }
    });
});

function validateForm(username, email, password, confirmPassword) {
    const messageElement = document.getElementById('message');
    
    if (username.length < 3) {
        messageElement.textContent = 'Username must be at least 3 characters';
        messageElement.style.color = 'red';
        return false;
    }
    
    if (!email.includes('@') || !email.includes('.')) {
        messageElement.textContent = 'Please enter a valid email';
        messageElement.style.color = 'red';
        return false;
    }
    
    if (password.length < 6) {
        messageElement.textContent = 'Password must be at least 6 characters';
        messageElement.style.color = 'red';
        return false;
    }
    
    if (password !== confirmPassword) {
        messageElement.textContent = 'Passwords do not match';
        messageElement.style.color = 'red';
        return false;
    }
    
    return true;
}

// Sanitize input to prevent XSS attacks
function sanitizeInput(input) {
    const div = document.createElement('div');
    div.textContent = input;
    return div.innerHTML;
}