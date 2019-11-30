## Documentation helps greatly when it comes to detecting substrings via the slice function.
## https://docs.python.org/3/tutorial/introduction.html#strings
similarSubs= []

word = "string"
#word = word.replace(" ", "")

n = 3
j = n
x = 0

# Find substrings
while x < (len(word)):
    similarSubs.append(word[x:j])
    j+=1
    x+=1
    # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
    if (len(word[x:j]) != n):
        break
print(similarSubs)