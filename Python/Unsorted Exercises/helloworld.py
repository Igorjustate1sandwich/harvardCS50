# Basic syntax and functions

# Ask for name and age and get input
print("Hello. What is your name?")
name = input()                      # takes input as a string
print("Hello", name)
print("How old are you?")
age = input()                       # takes input as a string

# Print name and age. 'f' = format and is a requirement.
print(f"You are {name} and you are {age} years old.")

# Tell user their age in one years time by typesetting str into int + 1.
print("Next year you will be " + str(int(age) + 1) + " years old.") 

# Goodbye 
print("Goodbye.\nHave a nice day.")

# You use end = "" to prevent a new line.
print("Hello", end="")
print("World")