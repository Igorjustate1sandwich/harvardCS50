# crackTest3.py only tests three letters that are either lowercase, uppercase, or a combo.


# crypt() is a password encryption function
# key is the users typed password. This is what you want to hash.
# salt is the first two characters of the hashed password

import crypt
import string

alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)
counter = 0

# real password in plaintext
password = "emc"

# salt for testing purposes
salt = "50"

# hash of password 
hash = crypt.crypt(password, salt)

# check only for a lowercase pword
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

# check for a combination of lowercase & uppercase, or a fully uppercase pword
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            counter += 1
            tempPass0 = alphaLow[i] + alphaLow[j] + alphaUp[k]      # caT
            tempPass1 = alphaLow[i] + alphaUp[j] + alphaLow[k]      # cAt
            tempPass2 = alphaUp[i] + alphaLow[j] + alphaLow[k]      # Cat
            tempPass3 = alphaLow[i] + alphaUp[j] + alphaUp[k]       # cAT
            tempPass4 = alphaUp[i] + alphaUp [j] + alphaLow[k]      # CAt
            tempPass5 = alphaUp[i] + alphaLow[j] + alphaUp[k]       # CaT
            tempPass6 = alphaUp[i] + alphaUp[j] + alphaUp[k]        # CAT

            tempHash0 = crypt.crypt(tempPass0, salt)
            tempHash1 = crypt.crypt(tempPass1, salt)
            tempHash2 = crypt.crypt(tempPass2, salt)
            tempHash3 = crypt.crypt(tempPass3, salt)
            tempHash4 = crypt.crypt(tempPass4, salt)
            tempHash5 = crypt.crypt(tempPass5, salt)
            tempHash6 = crypt.crypt(tempPass6, salt)

            if tempHash0 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass0}")
                exit()
            elif tempHash1 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass1}")
                exit()
            elif tempHash2 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass2}")
                exit()
            elif tempHash3 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass3}")
                exit()
            elif tempHash4 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass4}")
                exit()
            elif tempHash5 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass5}")
                exit()
            elif tempHash6 == hash:
                print(f"Attempt {counter} (combo) SUCCESS: PASSWORD = {tempPass6}")
                exit()
            else:
                print(f"Attempt {counter} (combo) FAIL: Passwords {tempPass0} or {tempPass1} or {tempPass2} or {tempPass3} or {tempPass4} or {tempPass5} or {tempPass6} are INCORRECT and != hash {hash}")



