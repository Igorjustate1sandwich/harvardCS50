# dict2.py: Nested Dictionaries
# https://www.youtube.com/watch?v=P16-o-bRsTU


# Initialize dictionaries
user = {
    1: {'name': 'stndn', 'age': '100'},
    2: {'name': 'Bob', 'age': '49'}
}

fruit = {
    'Apple': {'Quantity': 3, 'Cost': 2.50},
    'Mango': {'Quantity': 8, 'Cost': 4.30},
    'Banana': {'Quantity': 6, 'Cost': 3.60}
}

# Output
print(f"{user[2]['name']} loves his apples so much he bought {fruit['Apple']['Quantity']} of them!")
print("Quantity of banana's in the warehouse:", fruit['Banana']['Quantity'])
