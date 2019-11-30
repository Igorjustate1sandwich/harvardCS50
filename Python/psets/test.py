import sys
import nltk.tokenize

text = "To love, or to have loved,this suffices. Demand nothing more. There is no other pearl to be found in the shadowy folds of life. Some text."

text2 = nltk.tokenize.sent_tokenize(text, language='english')
print(text2)