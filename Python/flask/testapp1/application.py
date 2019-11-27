from flask import Flask
app = Flask(__name__)

answer = "Orange"

@app.route('/')
def hello_world():
    return(answer)