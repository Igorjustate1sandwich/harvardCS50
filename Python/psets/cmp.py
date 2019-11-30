# working file for pset7 (similarities)
import sys
from nltk.tokenize import sent_tokenize


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

# Compare lines in text1 and text2 and print similarities
ctr = 0
for sentence in range(len(text1)):
    for j in range(len(text2)):
        if text1[sentence] == text2[j] and len(text1[sentence]) >=1:
            ctr += 1
            similarLines.append(text1[sentence])
            break           

print(ctr, similarLines)


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



# Output
print(ctr, similarSents)
