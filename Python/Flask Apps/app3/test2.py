# how to remove duplicates and maintain order
from collections import OrderedDict

fruits = ['apple', 'orange', 'orange', 'mango', 'orange']

print(fruits)
print(set(fruits))      # removes duplicates but order is lost
print(list(OrderedDict.fromkeys(fruits)))   # removes duplicates and order is maintained

oFruits = list(OrderedDict.fromkeys(fruits)) 
