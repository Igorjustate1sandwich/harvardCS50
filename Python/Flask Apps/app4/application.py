from flask import Flask, render_template, request, redirect, flash
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
import sqlite3

app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure Session Information
    # todo

# Setup SQLite3 - create connection object that represents database
con = sqlite3.connect("ideacloud.db", check_same_thread=False)

# Create a cursor object which will send commands to SQL
db = con.cursor()

# index
@app.route("/")
def index():
    return render_template("index.html")

# register
@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form['username']
        password = request.form['password']
        confirmation = request.form['confirmation']

        # Check if username is available
        rows = db.execute("SELECT * FROM users")
        for row in rows:
            if username == (f"{row[1]}"):
                print("NAME IS TAKEN")
                return redirect("register")
        
        # Check if input is valid
        if len(username) <1:
            print("Username not valid!")
            return redirect("register")
        elif len(password) <1 or password != confirmation:
            print("Password not valid!")
            return redirect("register")
        
        # Hash password 
        hash = generate_password_hash(password, 'pbkdf2:sha256', salt_length=8)

        # Insert user details to the database
        with con:
            rows = db.execute(f"INSERT INTO users (name, hash) VALUES('{username}', '{hash}')")

        # Success
        return redirect("register")

    else:
        return render_template("register.html")

# login
@app.route("/login", methods=["GET", "POST"])
def login():
    # Forget any user_id
        # todo

    if request.method == "POST":
        # Ensure username has been submitted
        if not request.form.get("username"):
            print("NO USERNAME")
            return redirect("login")

        # Ensure password has been submitted
        if not request.form.get("password"):
            print("NO PASSWORD")
            return redirect("login")

        # Validate information by querying the database
        username = request.form.get("username")

        with con:
            db.execute("SELECT * FROM users WHERE name = :username", {"username": username})
            rows = db.fetchall()

            # Check if user exists and validate password
            if len(rows) != 1 or not check_password_hash(rows[0][2], request.form.get("password")):
                print("Username/password is invalid")
                return render_template("login.html")

            # Login successful
            else:
                print(rows)
                
                # Remember which user has logged in
                    # todo
                
                # Redirect user to homepage
                return redirect("/")

    else:
        return render_template("login.html")

if __name__ == "__main__":
    app.run(debug=True)

