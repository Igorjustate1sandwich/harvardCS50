import sqlite3



# Setup SQLite3 - create connection object that represents database
connection = sqlite3.connect("ideacloud.db")

# Create a cursor object which will send commands to SQL
db = connection.cursor()

#cur.execute("CREATE TABLE cars(id INT, name TEXT, price INT)")

with connection:
    db.execute("INSERT INTO users (id,name,hash) VALUES (1, 'standon', '6fj283k')")


