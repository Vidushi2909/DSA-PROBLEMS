document.addEventListener('DOMContentLoaded', function() {
    
    const form = document.getElementById('loginForm');
    
    form.addEventListener('submit', async function(event) {
        event.preventDefault();
        
        const email = document.getElementById('loginEmail').value;
        const password = document.getElementById('loginPassword').value;
        
        if (!validateLogin(email, password)) {
            return;
        }
        
        // Sanitize inputs
        const sanitizedEmail = sanitizeInput(email);
        
        try {
            const response = await fetch('/api/login', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({
                    email: sanitizedEmail,
                    password: password
                })
            });
            
            const data = await response.json();
            const messageElement = document.getElementById('loginMessage');
            
            if (data.success) {
                messageElement.textContent = data.message;
                messageElement.style.color = 'green';
                
                // Redirect to dashboard
                setTimeout(() => {
                    window.location.href = 'dashboard.html';
                }, 1000);
            } else {
                messageElement.textContent = data.message;
                messageElement.style.color = 'red';
            }
            
        } catch (error) {
            document.getElementById('loginMessage').textContent = 'Error connecting to server';
            document.getElementById('loginMessage').style.color = 'red';
        }
    });
});

function validateLogin(email, password) {
    const messageElement = document.getElementById('loginMessage');
    
    if (!email || email.trim() === '') {
        messageElement.textContent = 'Email is required';
        messageElement.style.color = 'red';
        return false;
    }
    
    if (!password || password.trim() === '') {
        messageElement.textContent = 'Password is required';
        messageElement.style.color = 'red';
        return false;
    }
    
    if (!email.includes('@') || !email.includes('.')) {
        messageElement.textContent = 'Please enter a valid email';
        messageElement.style.color = 'red';
        return false;
    }
    
    return true;
}

function sanitizeInput(input) {
    const div = document.createElement('div');
    div.textContent = input;
    return div.innerHTML;
}