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
hash = "50nVxcXb1Y2Hg"

# check for a lowercase and uppercase pword
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                for m in range (0, 26):
                    tempPass0 = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] + alphaLow[m]
                    tempHash0 = crypt.crypt(tempPass0, salt)
                    counter += 1
                    
                    if tempHash0 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass0} as {tempHash0} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    else:
                        print(f"Attempt {counter} FAIL: {tempPass0} = {tempHash0} is not equal to {hash} | {time.time() - start_time:.2f} seconds")





