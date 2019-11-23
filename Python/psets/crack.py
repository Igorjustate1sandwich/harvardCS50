# Crack a 1 to 5 character alphabetical password that has been hashed via DES level encryption
# Accounts for case permutations via "alphabet", loop modifications and strip(). 
# Accuracy is high, speed is much faster than v2 but much slower than v1 for non permutations (e.g. "AAAZ" or "aaaz")
# Generate test hashes via https://unix4lyfe.org/crypt/ 

import crypt
import time

# Track time
start_time = time.time()

counter = 0
salt = "50"
hash = "50yKr2Re0RQqs"
alphabet = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

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
                    counter+= 1
                    print(f"Attempt {counter} FAIL: {tempPass} = {tempHash} != {hash} | {time.time() - start_time:.2f} seconds")    