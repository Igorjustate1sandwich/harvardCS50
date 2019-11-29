from flask import Flask, render_template

app = Flask(__name__)

# homepage
@app.route("/")
def index():
    return render_template("index.html")

# about page
@app.route("/about")
def about():
    return render_template("about.html")

# features page
@app.route("/features")
def features():
    return render_template("features.html")

if __name__ == "__main__":
    app.run(debug=True)
