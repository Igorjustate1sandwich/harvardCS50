from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""
    similarLines = []
    text1 = a.splitlines()
    text2 = b.splitlines()

    for sentence in range(len(text1)):
        for j in range(len(text2)):
            if text1[sentence] == text2[j] and len(text1[sentence]) >= 1:
                similarLines.append(text1[sentence])
                break
    return (similarLines)


def sentences(a, b):
    """Return sentences in both a and b"""
    similarSents = []
    text1 = sent_tokenize(a)
    text2 = sent_tokenize(b)

    # Compare sentences in text1 and text2 and print similarities
    for sentence in range(len(text1)):
        for j in range(len(text2)):
            if text1[sentence] == text2[j] and len(text1[sentence]) >= 1:
                similarSents.append(text1[sentence])
                break
    return (set(similarSents))


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""
    similarSubs = []
    text1 = a.replace("\n", "")
    text2 = b.replace("\n", "")

    # Check if substring length is longer than string length
    if (n > len(a)) or (n > len(b)):
        return(0)

    # Find all substrings in text1
    substrings1 = []
    x = 0
    j = n
    while x < len(text1):
        substrings1.append(text1[x:j])
        j += 1
        x += 1
        # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
        if (len(text1[x:j]) != n):
            break

    # Find all substrings in text2
    substrings2 = []
    x = 0
    j = n
    while x < len(text2):
        substrings2.append(text2[x:j])
        j += 1
        x += 1
        # If a potential substring is not exactly n characters long then QUIT as there are no more substrings to find.
        if (len(text2[x:j]) != n):
            break

    # Compare and return
    similarSubs = set(substrings1).intersection(set(substrings2))
    return (similarSubs)

