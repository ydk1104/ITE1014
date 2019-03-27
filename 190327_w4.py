def printN() :
    N = int(input())
    for i in range(1, N+1) :
        print(i)

def printN2() :
    N = int(input())
    for i in range(1, N+1) :
        if(i%2==0 and i%4==2) : continue
        print(i)

def cmp(var1, var2) :
    if var1>var2 : return 1
    if var1<var2 : return -1
    return 0

def compare() :
    N = input()
    a = N.split(' ')
    print(cmp(a[0], a[1]))

def findN() :
    import random
    N = random.randint(0, 100)
    guess = -1
    while N != guess :
        guess = int(input("Number=?\n"))
        print(guess)
        if cmp(guess, N) == -1 :
            print("Larger than " + str(guess) + ".")
        if cmp(guess, N) == 1 :
            print("Smaller than " + str(guess) + ".")
    print("Yes. Right.")

def print1toN(N) :
    for i in range(1, N+1) :
        print(str(i) + " ", end='')
    print()

def printN3() :
    N = int(input())
    i = 1
    while(i<=N) :
        print1toN(i)
        i+=1
    i-=1
    while(i>=1) :
        print1toN(i)
        i-=1

def RPS() :
    import random
    retry = 'yes'
    win=0
    lose=0
    while retry != 'no' :
        com = random.randint(0, 2)
        user = input()
        if user == 'rock' : user = 0
        elif user == 'paper' : user = 1
        elif user == 'scissors' : user = 2
        if user == (com+1)%3 :
            print("You win!")
            win+=1
        else :
            print("You Lose!")
            lose+=1
        print(com)
        retry = input("Retry?\n")
    print (win / (win+lose))

def drawstar(star, blank) :
    print('*' * star + ' ' * blank + '*' * star)

def printstar() :
    N = int(input())
    i = N-1
    star = 0
    print('*'*(N*2-1))
    while i>=1 :
        drawstar(i, (N-i)*2-1)
        star += i*2
        i-=1
    i+=2
    while i<=N-1 :
        drawstar(i, (N-i)*2-1)
        star += i*2
        i+=1
    print('*'*(N*2-1))
    star += N*4-2
    print(star)
N = int(input())
if N == 1 :
    printN()
elif N == 2 :
    printN2()
elif N == 3 :
    compare()
elif N == 4 :
    findN()
elif N == 5 :
    printN3()
elif N == 6 :
    RPS()
elif N == 7 :
    printstar()
