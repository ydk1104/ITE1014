print("*"*7 + " START " + "*"*7)
import random
i = 0
while(i<3) :
    a = random.randint(0, 9)
    b = random.randint(0, 9)
    ans = int(input(str(a) + " * " + str(b) + " = ?"))
    if(ans == a*b) : print("Correct Answer")
    else : print("Wrong Answer, "+ str(a) + " * " + str(b) + " = " + str(a*b))
    i+=1
