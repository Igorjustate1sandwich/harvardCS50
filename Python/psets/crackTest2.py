# crackTest2.py only tests two letters that are either lowercase, uppercase, or a combo.

# crypt() is a password encryption function
# key is the users typed password. This is what you want to hash.
# salt is the first two characters of the hashed password

import crypt
import string

alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)
counter = 0

# real password in plaintext
password = "GF"

# salt for testing purposes
salt = "51"

# hash of password 
hash = crypt.crypt(password, salt)

# test only lowercase
for i in range (0, 26):
    for j in range (0, 26):
        tempPass = alphaLow[i] + alphaLow[j]
        tempHash = crypt.crypt(tempPass, salt)
        counter += 1

        if tempHash == hash:
            print(f"Attempt {counter} (lower) SUCCESS: PASSWORD = {tempPass}")
            exit()
        else:
            print(f"Attempt {counter} (lower) FAIL: {tempPass} = {tempHash} is not equal to {hash}")

# check for a combination of lowercase & uppercase, or a fully uppercase pword
for i in range (0, 26):
    for j in range (0, 26):
        counter+= 1
        tempPass0 = alphaLow[i] + alphaUp[j]        # aB
        tempPass1 = alphaUp[i] + alphaLow[j]        # Ab
        tempPass2 = alphaUp[i] + alphaUp[j]         # AB

        tempHash0 = crypt.crypt(tempPass0, salt)
        tempHash1 = crypt.crypt(tempPass1, salt)
        tempHash2 = crypt.crypt(tempPass2, salt)

        if tempHash0 == hash: 
            print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass0}")
            exit()
        elif tempHash1 == hash:
            print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass1}")
            exit()
        elif tempHash2 == hash:
            print(f"Attempt {counter} (upper) SUCCESS: PASSWORD = {tempPass2}")
            exit()
        else:
            print(f"Attempt {counter} (combo) FAIL: {tempPass0} = {tempHash0} is not equal to {hash} || {tempPass1} = {tempHash1} is not equal to {hash}")
        
        
