# Crack all 3 to 5 character alphabetical passwords that have been hashed via DES level encryption
# Accounts for case permutations via itertools, so accuracy is high but speed is significantly slower than V1.

import crypt
import string
import time
from itertools import product

# Track time
start_time = time.time()

# Define alphabet
alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)

# Variables
counter = 0
salt = "50"
hash = "50Qy0qSHwb..E"
tempHashList= []

# Create all uppercase and lowercase permutations of a string
# example "apple" = applE, appLe, apPle etc...
def casePermutate(word):
    list = [(c, c.upper()) if not c.isdigit() else (c,) for c in word.lower()]
    return ["".join(item) for item in product(*list)]

# crack a 3 character password
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
                # Create temp passwords that are fully lowercase 
                tempPass = alphaLow[i] + alphaLow[j] + alphaLow[k] 
                 # Create temp passwords that are a combination of lower and uppercase characters
                tempPassList = casePermutate(tempPass)

                # Create temp hash values by feeding temp passwords into crypt()
                for z in range (len(tempPassList)):
                    tempHashList.append(crypt.crypt(tempPassList[z], salt))

                    for y in range (len(tempHashList)):
                        if tempHashList[y] == hash:
                            print(f"\nSUCCESS: PASSWORD = {tempPassList[z]} as test hash {tempHashList[y]} = {hash} \n")
                            print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                            exit()
                        counter+= 1
                        print(f"Attempt {counter} FAIL: {tempPassList[z]} = {tempHashList[y]} != {hash} | {time.time() - start_time:.2f} seconds")  

# crack a 4 character password
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                    # Create temp passwords that are fully lowercase 
                    tempPass = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] 
                    # Create temp passwords that are a combination of lower and uppercase characters
                    tempPassList = casePermutate(tempPass)

                    # Create temp hash values by feeding temp passwords into crypt()
                    for z in range (len(tempPassList)):
                        tempHashList.append(crypt.crypt(tempPassList[z], salt))

                        for y in range (len(tempHashList)):
                            if tempHashList[y] == hash:
                                print(f"\nSUCCESS: PASSWORD = {tempPassList[z]} as test hash {tempHashList[y]} = {hash} \n")
                                print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                                exit()
                        counter+= 1
                        print(f"Attempt {counter} FAIL: {tempPassList[z]} = {tempHashList[y]} != {hash} | {time.time() - start_time:.2f} seconds")    

# crack a 5 character password
for i in range (0, 26):
    for j in range (0, 26):
        for k in range (0, 26):
            for n in range (0, 26):
                for m in range (0, 26):
                    # Create temp passwords that are fully lowercase 
                    tempPass = alphaLow[i] + alphaLow[j] + alphaLow[k] + alphaLow[n] + alphaLow[m]
                    # Create temp passwords that are a combination of lower and uppercase characters
                    tempPassList = casePermutate(tempPass)

                    # Create temp hash values by feeding temp passwords into crypt()
                    for z in range (len(tempPassList)):
                        tempHashList.append(crypt.crypt(tempPassList[z], salt))

                        for y in range (len(tempHashList)):
                            if tempHashList[y] == hash:
                                print(f"\nSUCCESS: PASSWORD = {tempPassList[z]} as test hash {tempHashList[y]} = {hash} \n")
                                print(f"***** Cracked in {time.time() - start_time:.4f} seconds *****\n ")
                                exit()