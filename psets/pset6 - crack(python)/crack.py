# Crack a 1 to 5 character alphabetical password that has been hashed via DES level encryption
# Accounts for case permutations via "alphabet", loop modifications and strip().
# Accuracy is high, speed is much faster than v2 but much slower than v1 for non permutations (e.g. "AAAZ" or "aaaz")
# Generate test hashes via https://unix4lyfe.org/crypt/

import sys
import crypt
import time

# Argument check
if len(sys.argv) != 2:
    print("\nIncorrect Usage! Format: python3 crack.py hashvalue\n")
    exit()

# Variables
ctr = 0                     # Used to track attempts.
hash = sys.argv[1]          # Get first argument to form hash.
salt = sys.argv[1][:2]      # Get first two characters of first argument to form salt.
alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

# Track time
start_time = time.time()

# crack a 5 character password
for i in (alphabet):
    for j in (alphabet):
        for k in (alphabet):
            for l in (alphabet):
                for m in (alphabet):
                    tempPass = (i+j+k+l+m).strip()
                    tempHash = crypt.crypt(tempPass, salt)

                    if tempHash == hash:
                        print(f"\nSUCCESS: PASSWORD = {tempPass} as {tempHash} = {hash} | {time.time() - start_time:.2f} seconds")
                        exit()
                    ctr+=1
                    print(f"Attempt {ctr} FAIL: {tempPass} = {tempHash} != {hash} | {time.time() - start_time:.2f} seconds")