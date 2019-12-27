from flask import Flask, render_template, request, redirect, flash, session
from tempfile import mkdtemp
from flask_session import Session
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import login_required
from collections import OrderedDict

import sqlite3
import datetime

app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure Session Information
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Setup SQLite3 - create connection object that represents database
con = sqlite3.connect("ideacloud.db", check_same_thread=False)

# Create a cursor object which will send commands to SQL
db = con.cursor()

# index
@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    user_posts_db = []
    user_posts = []
    user_time_db = []
    user_time = []
    user_post_count = 0
    postID_db = []
    postID = []

    # Retrieve user information from database
    with con:
        # Get username
        db.execute("SELECT name FROM users WHERE id = :id", {"id": session["user_id"]})
        name = db.fetchall()

        # Get post history
        rows = db.execute("SELECT post from posts WHERE id = :id", {"id": session["user_id"]})
        for row in rows:
            user_posts_db.append(row)
            user_post_count += 1
        
        # Get time history
        times = db.execute("SELECT time from posts WHERE id = :id", {"id": session["user_id"]})
        for time in times:
            user_time_db.append(time)

        # Get postID 
        pID = db.execute("SELECT postID from posts WHERE id = :id", {"id": session["user_id"]})
        for post in pID:
            postID_db.append(post)
        
    # Slice characters and clean posts
    for i in range(user_post_count):
        temp = str(user_posts_db[i])
        user_posts.append(temp[1:-2])
        temp = str(user_time_db[i])
        user_time.append(temp[2:-3])
        temp = str(postID_db[i])
        postID.append(temp[1:-2])
        print(postID[i])

    if request.method == "POST":            # Submission handler
        # Get text from submission box 
        text = request.form['text']

        # Check if text meets requirements (max 240 characters, min 1 character)
        if len(text) > 240 or len(text) <1:
            print("Error: Invalid Text")
            return render_template("index.html", name=name[0][0])

        # Store text as submission within database
        with con:
            # Save date and time of post
            datetimeObj = datetime.datetime.now().strftime("%Y-%m-%d %I:%M %p")
            # Write to DB
            rows = db.execute("INSERT INTO posts (id, name, post, time) VALUES(?, ?, ?, ?)", (session["user_id"], name[0][0], text, datetimeObj))

        return redirect("/")
    else:
        return render_template("index.html", name=name[0][0], posts = user_posts, postcount = user_post_count, time=user_time, postID = postID)

# delete
@app.route("/delete", methods=["POST"])
@login_required
def delete():
    if request.method == "POST":
        postID = request.form['name']
        print("postID =", postID)

        # Go to 'posts' database and delete the corresponding postID
        with con:
            db.execute("DELETE FROM posts WHERE postID = :postID", {"postID": postID})

        return redirect("/")
    else:
        return redirect("/")

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
            rows = db.execute("INSERT INTO users (name, hash) VALUES(?, ?)", (username, hash))
            #rows = db.execute(f"INSERT INTO users (name, hash) VALUES('{username}', '{hash}')")

        # Success
        return redirect("login")

    else:
        return render_template("register.html")

# login
@app.route("/login", methods=["GET", "POST"])
def login():
    # Forget any user_id
    session.clear()

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
                session["user_id"] = rows[0][0]
                
                # Redirect user to homepage
                return redirect("/")

    else:
        return render_template("login.html")

if __name__ == "__main__":
    app.run(debug=True)

