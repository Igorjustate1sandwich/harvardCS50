# Crack a five character alphabetical password that has been hashed via DES level encryption

import crypt
import string
import time

# Track time
start_time = time.time()

# Define alphabet
alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)
counter = 0

# salt 
salt = "50"

# password hash
hash = "50ingKHiO9hUQ"

# check only for a lowercase pword
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                for m in range (0, 26):
                    tempPass = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] + alphaLow[m]
                    tempHash = crypt.crypt(tempPass, salt)
                    counter += 1
                    
                    if tempHash == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass} as {tempHash} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    else:
                        print(f"Attempt {counter} FAIL: {tempPass} = {tempHash} is not equal to {hash} | {time.time() - start_time:.2f} seconds")





