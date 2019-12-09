# Introduction to HTTP Methods and retrieving form data.
# We pass data from HTML to Flask, and then back to another HTML page.

from flask import Flask, render_template, request, redirect

app = Flask(__name__)

# index
@app.route("/")
def index():
    return render_template("index.html")

# handle user information and then redirect to welcome page
@app.route("/process", methods=["GET", "POST"])
def process():

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        name = request.form['name']
        age = request.form['age']
        food = request.form['food']
        gender = request.form['gender']
        return render_template("welcome.html", name = name, age = age, food = food, gender = gender)

    # User reached route via GET (as by clicking a link or via redirect)
        # e.g. user manually entered /process in URL bar without filling any form data - we need to account for this.
    else:
        return redirect("/")

if __name__ == "__main__":
    app.run(debug=True)