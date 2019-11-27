import turtle  
line = turtle.Turtle() 

ctr = 0
for i in range(12): 
    for j in range(3):
        line.forward(55 + ctr) 
        line.left(55 + ctr) 
        ctr += 5
        
ctr = 0
for i in range(12): 
    for j in range(3):
        line.back(55 + ctr) 
        line.right(55 + ctr) 
        ctr += 5

turtle.done() 