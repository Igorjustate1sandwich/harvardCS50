# crypt() is a password encryption function
# key is the users typed password. This is what you want to hash.
# salt is the first two characters of the hashed password

import crypt
import sys

# real password in plaintext
password = "rob"

# hashed variant of above password
hashedPassword = "51v3Nh6ZWGHOQ"

# salt for hashedPassword = first two characters
salt = "51" #this is just a fake test salt for testing purposes

print("\n", crypt.crypt("b", salt))

