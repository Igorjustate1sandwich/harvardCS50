# Objective: print all uppercase and lowercase permutations of a word
# Example: "cat" == ['cat', 'caT', 'cAt', 'cAT', 'Cat', 'CaT', 'CAt', 'CAT']
# For use in crack.py

## CODE REFERENCED FROM
## https://stackoverflow.com/questions/20063721/string-manipulation-in-python-all-upper-and-lower-case-derivatives-of-a-word


from itertools import product

def casePermutate(word):
    list = [(c, c.upper()) if not c.isdigit() else (c,) for c in word.lower()]
    return ["".join(item) for item in product(*list)]


string0 = casePermutate("apple")

string1 = "apple"
list = casePermutate(string1)
print(list)
