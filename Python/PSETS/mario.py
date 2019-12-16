height = 4

for i in range (height):
    for j in range (height-i):
        print(" ", end="")      # print whitespace
    for k in range (i+1):
        print("#", end="")      # print n hashes on one line

    print()                     # move to next line
    


# pseudocode
# 1. print 7 spaces and 1 hash
# 2. print 6 spaces and 2 hashes
# 3. print 5 spaces and 3 hashes