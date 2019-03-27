def printf(a, b, c, d, e) :
    a = str(a)
    b = str(b)
    c = str(c)
    d = str(d)
    print(a + " * " + b + " + " + c + " - " + d + " = " + e)

print("*"*7 + " START " + "*"*7)
import random
i = 0
while(i<3) :
    a = random.randint(0, 9)
    b = random.randint(0, 9)
    c = random.randint(0, 9)
    d = random.randint(0, 9)
    printf(a, b, c, d, "?")
    import time
    for j in range(1, 4) :
        print(str(j) + ", ", end='')
        time.sleep(1)
    print(": ", end='')
    ans = int(input())
    if(ans == a*b+c-d) : print("Correct Answer")
    else :
        print("Wrong Answer, ", end='')
        printf(a, b, c, d, str(a*b+c-d))
    i+=1
