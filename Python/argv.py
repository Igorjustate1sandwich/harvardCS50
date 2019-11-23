# Implemention of argv in python with basic out of bounds checking.
# remember that argv[0] is reserved for the name of the program.

import sys

if (len(sys.argv)) != 3:
    print("Not enough arguments.")
    exit()

name = sys.argv[1]
age = sys.argv[2]

print(f"Hello {name}. You're {age} years old.")
print(f"The first two characters of your name is {name[:2]}.")
