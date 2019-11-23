import crypt
import string

alphaLow = list(string.ascii_lowercase)
alphaUp = list(string.ascii_uppercase)

test=[]
test.append(crypt.crypt("cat", "50"))
test.append(crypt.crypt("dog", "50"))
test.append(crypt.crypt("eel", "50"))


#for i in range (len(test)):
    #print(test[i])

print(crypt.crypt("aaaab","50"))