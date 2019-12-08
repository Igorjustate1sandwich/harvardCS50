# Introduction to HTTP Methods and retrieving form data.
# We pass data from HTML to Flask, and then back to another HTML page.

from flask import Flask, render_template, request, redirect

app = Flask(__name__)

# index
@app.route("/")
def index():
    return render_template("index.html")

# handle user information and then redirect to welcome page
@app.route("/process", methods=['POST'])
def process():
    name = request.form['name']
    age = request.form['age']
    food = request.form['food']
    gender = request.form['gender']
    return render_template("welcome.html", name = name, age = age, food = food, gender = gender)

if __name__ == "__main__":
    app.run(debug=True)