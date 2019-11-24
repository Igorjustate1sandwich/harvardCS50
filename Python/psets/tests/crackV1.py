# Crack a five character alphabetical password that has been hashed via DES level encryption
# Does NOT account for case permutations, so speed is much faster but less accurate.

import crypt
import string
import time
import sys

# Track time
start_time = time.time()

# Define alphabet
alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)

# Argument check
if len(sys.argv) != 2:
    print("\nIncorrect Usage! Format: python3 crack.py hashvalue\n")
    exit()

# Variables
counter = 0                     # Used to track attempts.
hash = sys.argv[1]          # Get first argument to form hash.
salt = sys.argv[1][:2]      # Get first two characters of first argument to form salt.


# check for a 3 character password
for i in range (0, 26): 
    for j in range (0, 26):
        for k in range (0, 26):
                    counter+= 1
                    tempPass0 = alphaLow[i] + alphaLow[j] + alphaLow[k] 
                    tempPass1 = alphaUp[i] + alphaUp[j] + alphaUp[k] 

                    tempHash0 = crypt.crypt(tempPass0, salt)
                    tempHash1 = crypt.crypt(tempPass1, salt)

                    if tempHash0 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass0} as {tempHash0} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    elif tempHash1 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass1} as {tempHash1} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit() 
                    else:
                        print(f"Attempt {counter} FAIL: {tempPass0} = {tempHash0} is not equal to {hash} | {time.time() - start_time:.2f} seconds")                        

# check for a 4 character password
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                    counter+= 1
                    tempPass0 = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] 
                    tempPass1 = alphaUp[i] + alphaUp[j] + alphaUp[k] + alphaUp[n] 

                    tempHash0 = crypt.crypt(tempPass0, salt)
                    tempHash1 = crypt.crypt(tempPass1, salt)

                    if tempHash0 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass0} as {tempHash0} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    elif tempHash1 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass1} as {tempHash1} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit() 
                    else:
                        print(f"Attempt {counter} FAIL: {tempPass0} = {tempHash0} is not equal to {hash} | {time.time() - start_time:.2f} seconds")                    
                   
# check for a 5 character password
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                for m in range (0, 26):
                    counter+= 1
                    tempPass0 = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] + alphaLow[m]
                    tempPass1 = alphaUp[i] + alphaUp[j] + alphaUp[k] + alphaUp[n] + alphaUp[m]

                    tempHash0 = crypt.crypt(tempPass0, salt)
                    tempHash1 = crypt.crypt(tempPass1, salt)

                    if tempHash0 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass0} as {tempHash0} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    elif tempHash1 == hash:
                        print(f"\nAttempt {counter} SUCCESS: PASSWORD = {tempPass1} as {tempHash1} is equivalent to {hash}")
                        print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                        exit()
                    else:
                        print(f"Attempt {counter} FAIL: {tempPass0} = {tempHash0} is not equal to {hash} | {time.time() - start_time:.2f} seconds")

print(f"UPDATE: Password is not 5 characters long or could not be cracked | {time.time() - start_time:.4f} seconds")
exit()