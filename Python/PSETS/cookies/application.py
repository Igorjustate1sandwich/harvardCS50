from flask import Flask, render_template, request, redirect, session
from flask_session import Session

# Flask
app = Flask(__name__)
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure Sessions
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Storefront Items
ITEMS = ["apple", "mango"]

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/purchase", methods=["POST"])
def purchase():
    for item in request.form:
        session[item] = int(request.form.get(item))
    return redirect("/cart")

@app.route("/cart")
def cart():
    return render_template("cart.html", cart=session)