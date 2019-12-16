import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session, url_for, make_response
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash
from collections import OrderedDict

from helpers import apology, login_required, lookup, usd

#APIKEY: pk_6fbe54f5df8a4f62b1c220b5db2cbd15

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stock_val = []
    stockVal = []
    total_assets = 0
    totalAssetPrice = []
    global symbols
    symbols = []
    names = []
    quantity = []

    cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
    rows = db.execute("SELECT stock, quantity FROM portfolio WHERE ID = :id", id = session["user_id"])

    # Generate structure of the table (stock: symbols, full company names)
    ctr=0
    for row in rows:
        # Calculate the $ value of the total assets a user has.
        stock_val.append(lookup(row['stock']))
        total_assets += stock_val[ctr]['price'] * row['quantity']

        # Store data (symbols & names) from portfolio into a Python list
        symbols.append(row['stock'])
        names.append(stock_val[ctr]['name'])

        # Remove duplicate items from the list
        symbols = list(OrderedDict.fromkeys(symbols))
        names = list(OrderedDict.fromkeys(names))
        ctr +=1

    # Generate structure of the table (stock: quantity of shares, share price, sum of individual shares)
    ctr=0
    qty = 0
    for symbl in symbols:
        database = db.execute("SELECT quantity,stock FROM portfolio WHERE ID = :id AND stock = :stock", id = session["user_id"], stock = symbl)
        for row in database:
            qty += row['quantity']
        quantity.append(qty)
        stockVal.append(lookup(row['stock']))                               #  Stock value for a symbol (e.g. NVDA)
        totalAssetPrice.append(stockVal[ctr]['price'] * quantity[ctr])      #  Total value for the amount of stocks owned for a certain symbol (e.g. NVDA)
        qty=0
        ctr+=1
    return render_template("index.html", size = len(symbols), symbols=symbols, names=names, quantity=quantity, total_ap=totalAssetPrice, stockVal=stockVal, cash=cash, assets=total_assets)


@app.route("/buy", methods=["GET", "POST"])     # Post = form submission, Get = link click
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = lookup(request.form['symbol'])
        try:
            shares = float(request.form['shares'])
        except:
            return apology("Value must be integer", 400)

        try:
            shares = int(request.form['shares'])
        except:
            return apology("Value cannot be a float")

        shares = int(request.form['shares'])

        # Check if user input is blank or invalid
        if symbol == None or symbol == '':
            return apology("Invalid Symbol", 400)
        elif shares == '' or shares < 1:
            return apology("You must purchase at least one share", 400)

        price = symbol['price'] * int(shares)

        # Check if user has enough money
        rows = db.execute("SELECT * FROM users where id = :id", id=session["user_id"])
        for row in rows:
            bal = row['cash']
            if bal < price:
                return apology("Not enough money!", 400)

        # Deduct money from user database
        rows = db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=bal-price, id=session["user_id"])

        # Record transaction in 'History'
        rows = db.execute("INSERT INTO history (id,stock,quantity,price) VALUES (:id, :stock, :quantity, :price)", id=session["user_id"], stock=symbol['symbol'], quantity=shares, price=symbol['price'])

        pfRows = db.execute("SELECT * FROM portfolio where id = :id", id=session["user_id"])
        # If user has purchased this stock before then simply UPDATE "shares" to existing "quantity" in 'Portfolio'
        for row in pfRows:
            if symbol['symbol'] == row['stock']:
                db.execute("UPDATE portfolio SET quantity = :quantity WHERE id = :id AND stock = :stock", quantity= int(shares) + row['quantity'] , id=session["user_id"], stock=symbol['symbol'])
                return redirect("/")

        # If user has never purchased this stock before than create a new entry in 'Portfolio'
        rows = db.execute("INSERT INTO portfolio (id,stock,quantity) VALUES (:id, :stock, :quantity)", id=session["user_id"], stock=symbol['symbol'], quantity=shares )
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/check", methods=["GET"])
def check():
    """Return true if username available, else false, in JSON format"""
    username = request.args.get("username")
    password = request.args.get("password")
    confirmation = request.args.get("confirmation")

    # Check if username is taken
    rows = db.execute("SELECT * FROM users")
    for row in rows:
        if username == (f"{row['username']}"):
            return jsonify(False)
    # Input checking
    if len(username) <1:
        return jsonify(False), 400

    return jsonify(True)


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    stock = []
    quantity = []
    price = []
    time = []

    rows = db.execute("SELECT stock, quantity, price, time FROM history WHERE id = :id", id=session["user_id"])

    for row in rows:
        stock.append(row['stock'])
        quantity.append(row['quantity'])
        price.append(row['price'])
        time.append(row['time'])

    return render_template("history.html", size=len(stock), stock=stock, quantity=quantity, price=price, time=time)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        quote = lookup(request.form['symbol'])
        if quote != None:
            price = quote['price']
            name = quote['name']
            symbol = quote['symbol']
            print (price)
            return render_template("quoted.html", price=price, name=name, symbol=symbol)
        return apology("Invalid Symbol!", 400)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        username = request.form['username']
        password = request.form['password']
        confirmation = request.form['confirmation']

        #print("NOW IN REGISTER")
        rows = db.execute("SELECT * FROM users")
        for row in rows:
            if username == (f"{row['username']}"):
                return apology("Username Taken!", 400)

        # Input checking
        if password != confirmation:
            return apology("Passwords do not match!", 400)
        elif len(username) <1:
            return apology("Missing Username!", 400)
        elif len(password) <1:
            return apology("Missing Password!", 400)

        # Hash password, then insert new user into database
        else:
            hash = generate_password_hash(password,'pbkdf2:sha256', salt_length=8)
            rows = db.execute(f"INSERT INTO users (username, hash) VALUES('{username}', '{hash}')")
            return redirect("login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        shareQuantity = 0
        symbol = request.form.get('symbol')
        dropdown = symbol
        stock = dropdown
        shares = request.form['shares']

        print(dropdown, shares)

        # Check if user input is blank or invalid
        if shares == '' or int(shares) < 1:
            return apology("You must purchase at least one share", 400)

        # Check if user owns enough shares
        rows = db.execute("SELECT quantity FROM portfolio WHERE id = :id AND stock = :stock", id=session["user_id"], stock=stock)
        for row in rows:
            if int(shares) > row['quantity']:
                return apology("Not enough shares to sell!", 400)

        # Remove shares from user portfolio
        for row in rows:
            newQuantity = row['quantity'] - int(shares)

            if newQuantity !=0:
                db.execute("UPDATE portfolio SET quantity = :quantity WHERE id = :id AND stock = :stock", quantity = row['quantity'] - int(shares), id=session["user_id"], stock=stock)
            else:
                db.execute("DELETE FROM portfolio WHERE id = :id AND stock = :stock", id=session["user_id"], stock=stock)

        # Add value of shares to user balance and update 'portfolio'
        cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        newPrice = lookup(stock)

        newCash = cash[0]['cash'] + (newPrice['price'] * int(shares))
        db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash = newCash, id=session["user_id"])

        # Record transaction to 'history'
        print(stock,shares, newPrice['price'])
        db.execute("INSERT INTO history (id,stock,quantity,price) VALUES (:id, :stock, :quantity, :price)", id=session["user_id"], stock=stock, quantity=0-int(shares), price=newPrice['price'])

        # Success
        return redirect ("/")

    else:
        return render_template("sell.html", size=len(symbols), symbols=symbols)

@app.route("/admin", methods=["GET", "POST"])
@login_required
def admin():
    cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
    balance = cash[0]['cash']
    if request.method == "POST":
        print("POST")
        if request.form.get('500') == '$500':
            db.execute("UPDATE users SET cash = :cash WHERE id = :id", id=session["user_id"], cash=balance+500)

        elif request.form.get('2500') == '$2500':
            db.execute("UPDATE users SET cash = :cash WHERE id = :id", id=session["user_id"], cash=balance+2500)

        elif request.form.get('5000') == '$5000':
            db.execute("UPDATE users SET cash = :cash WHERE id = :id", id=session["user_id"], cash=balance+5000)

        cash = db.execute("SELECT cash FROM users WHERE id = :id", id=session["user_id"])
        return render_template("admin.html", cash=cash)

    if request.method == "GET":
        print("GET")
        return render_template("admin.html", cash=cash)

def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)

# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
