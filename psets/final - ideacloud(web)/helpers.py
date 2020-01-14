###################################
############ Ideacloud ############
######### Created by stndn ########
############ 12/30/19 #############
###################################

### Requirements:
# Sqlite3, Flask, Flask Sessions, werkzeug for password hashing/checking
    # and tempfile for session information.

### Concept:
# This is a webapp that allows users to sign up and make posts. 
# Cloud powered note taking: user posts are stored online in a database.
# Features stylish CSS design with emphasis on typography. 

### Video: https://youtu.be/QzLl9YKy9s0 

from flask import redirect, render_template, request, session
from functools import wraps

def login_required(f):
    """
    Decorate routes to require login.

    http://flask.pocoo.org/docs/1.0/patterns/viewdecorators/
    Code sourced from CS50 Finance
    """
    @wraps(f)
    def decorated_function(*args, **kwargs):
        if session.get("user_id") is None:
            return redirect("/login")
        return f(*args, **kwargs)
    return decorated_function

