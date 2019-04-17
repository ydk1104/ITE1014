def different(N) :
    check = [0]*10
    while N :
        if check[N%10] : return 0
        check[N%10]+=1
        N//=10
    return 1

def itos(N) :
    temp = []
    while N :
        temp.append(N%10)
        N//=10
    return temp

def baseball():
    MAX = 3
    targetNum = 111
    from random import randint
    #0-11, 988-999는 중복되는 숫자이므로 범위에서 제거함
    while(not different(targetNum)) : targetNum = randint(12, 987)
    print(targetNum)
    target = itos(targetNum)
    print(target)
    strike = 0
    ball = 0
    while strike != MAX :
        guess = int(input("0부터 999까지의 숫자를 입력해주세요, 중복되는 숫자는 피해주세요!"))
        while(not different(guess)) : guess = int(input("중복이 있어요! 다시 입력해주세요"))
        strike = 0
        ball = 0
        guess = itos(guess)
        for i in range(MAX) :
            if target[i] == guess[i] : strike+=1
            for j in range(MAX) :
                if i==j : continue
                if target[i] == guess[j] : ball+=1
        print(strike, "strike", ball, "ball")
    print("정답이에요! 숫자는 ", target, "였어요, 축하드려요!")
    N = input("다시하시겠어요? (yes or no)")
    if N == "yes" : return baseball()

def clap(N) :
    havetoclap = [3, 6, 9]
    check = False
    while N :
        if(N%10 in havetoclap) :
            check=True
            print("clap ", end='')
        N//=10
    if check : print()
    if check : return 1

def threesixnine() :
    N = int(input("마지막 숫자를 입력해 주세요"))
    for i in range(1, N+1) :
        if(not clap(i)) : print(i)
    
def printTest() :
    print("1 : 숫자야구")
    print("2 : 369")
    print("0 : exit")
    
def test():
    printTest()
    N = int(input())
    if N==0 : return
    work = [baseball, threesixnine]
    work[N-1]()
    return test()
