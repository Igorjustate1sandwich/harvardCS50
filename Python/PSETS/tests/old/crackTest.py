# crypt() is a password encryption function
# key is the users typed password. This is what you want to hash.
# salt is the first two characters of the hashed password

import crypt
import string

alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)
counter = 0

# real password in plaintext
password = "cat"

# salt for testing purposes
salt = "51"

# hash of password 
hash = crypt.crypt(password, salt)

# check lowercase
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            tempPass = alphaLow[i] + alphaLow[j] + alphaLow[k]
            tempHash = crypt.crypt(tempPass, salt)
            counter += 1

            if tempHash == hash:
                print(f"Attempt {counter} SUCCESS: PASSWORD = {tempPass}")
                exit()
            else:
                print(f"Attempt {counter} FAIL: {tempPass} = {tempHash} is not equal to {hash}")