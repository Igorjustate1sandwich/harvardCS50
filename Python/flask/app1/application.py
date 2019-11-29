# Very barebones website to show you the basics of flask
from flask import Flask, render_template

app = Flask(__name__)

names = ["Sahil", "Bob", "Snow", "Joe"]

@app.route("/")
def index():
    return render_template("index.html", names=names)

if __name__ == "__main__":
    app.run(debug=True)
