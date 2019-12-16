# WIP file for pset7: similarities
# This code is functionless and will run independently.
# Final code is in helpers.py
import sys
from nltk.tokenize import sent_tokenize


# Variables
n = 3
similarLines = []
similarSents = []
similarSubs = []

# Open files
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/LesMis1.txt", "r")
file1 = f.read()
f = open("/home/stndn/Documents/Git Repo/Learning/Python/psets/similarities/inputs/LesMis2.txt", "r")
file2 = f.read()

# Split strings into lines and store in list
text1 = file1.splitlines()
text2 = file2.splitlines()

# Compare lines in text1 and text2
ctr = 0
for sentence in range(len(text1)):
    for j in range(len(text2)):
        if text1[sentence] == text2[j] and len(text1[sentence]) >=1:
            ctr += 1
            similarLines.append(text1[sentence])
            break           

# Split strings into sentences and store in list
text1 = sent_tokenize(file1, language='english')
text2 = sent_tokenize(file2, language='english')

# Compare sentences in text1 and text2 and print similarities
ctr = 0
for sentence in range(len(text1)):
    for j in range (len(text2)):
        if text1[sentence] == text2[j] and len(text1[sentence]) >= 1:
            ctr += 1
            similarSents.append(text1[sentence])
            break

# Substrings
substrings = []

# Check if substring length is longer than string length
if (n > len(file1)) or (n > len(file2)):
    exit(0)

# Find all substrings in file1
substrings1 = []
x = 0
j = n
while x < len(file1):
    substrings1.append(file1[x:j])
    j += 1
    x += 1
    # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
    if (len(file1[x:j]) != n):
        break

# Find all substrings in file2
substrings2 = []
x = 0
j = n
while x < len(file2):
    substrings2.append(file2[x:j])
    j += 1
    x += 1
    # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
    if (len(file2[x:j]) != n):
         break

# Compare substrings in file1 to substrings in file2
    similarSubs = set(substrings1).intersection(set(substrings2))

# Final output
print(similarLines)
print(similarSents)
print(similarSubs)
