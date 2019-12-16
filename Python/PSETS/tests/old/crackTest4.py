# crackTest4.py tests cracks 3 letters that are lowercase and encrypted via DES
# In this example, hash value 50PaJ4.RO0YUo with salt = 50 will reveal password "abc"

import crypt
import string

# Define alphabet
alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)
counter = 0

# salt
salt = "50"

# password hash
hash = "50PaJ4.RO0YUo"

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