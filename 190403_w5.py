def add(a,b) : return a+b
def sub(a,b) : return a-b
def mul(a,b) : return a*b
def div(a,b) : return a/b

def main() :
    print("first operand is 0")
    N = 0
    operator = "1"
    while 1:
        operator = input("operator(+, -, *, /, exit)\n >> ")
        caninput = ["+", "-", "*", "/", "exit"]
        while operator not in caninput :
            operator = input("worng input\noperator(+, -, *, /, exit)\n >> ")
        if operator == "exit" : break;
        M = float(input("operand\n >> "))
        if operator == "+" :
            N = add(N,M)
        elif operator == "-" :
            N = sub(N,M)
        elif operator == "*" :
            N = mul(N,M)
        elif operator == "/" :
            N = div(N,M)
        print("result")
        print("-"*10)
        print(">>> " + str(N))
        print("-"*10)
    print("Terminate")

def callmain() :
    if __name__ == '__main__' :
        main()

def fibo(N) :
    if N==0 : return 0
    if N==1 : return 1
    return fibo(N-1) + fibo(N-2)

def printfibo() :
    N = int(input("fibo\n"))
    for i in range(N+1) :
        print("Fibonacci(" + str(i) + ")=" + str(fibo(i)))

def lists() :
    import random
    a = []
    for i in range(50) :
        a.append(random.randint(0, 1000))
    maxnum = -1
    minnum = 1001
    for i in a :
        print(i, end=' ')
        if maxnum < i : maxnum=i
        if minnum > i : minnum=i
    for i in range(len(a)) :
        for j in range(i+1, len(a)) :
            if a[i] > a[j] :
                a[i],a[j] = a[j],a[i];
    print()
    print("maxvalue = " + str(maxnum))
    print("minvalue = " + str(minnum))
    for i in a :
        print(i, end=' ')
    print()

def snail() :
    N = int(input("snail\n"))
    a = []
    for i in range(N+2) :
        temp = []
        for j in range(N+2) :
            temp.append(0)
        a.append(temp)
    cnt = 1
    x = -1
    y = 0
    while cnt<=N*N :
        while not a[x+1][y] and x<N-1 :
#         print(x, y, cnt)
            x+=1
            a[x][y] = cnt
            cnt+=1
#        x-=1
        while not a[x][y+1] and y<N-1 :
#          print(x, y, cnt)
            y+=1
            a[x][y] = cnt
            cnt+=1
#       y-=1
        while not a[x-1][y] and x>0 :
#           print(x, y, cnt)
            x-=1
            a[x][y] = cnt
            cnt+=1
#      x+=1
        while not a[x][y-1] and y>0 :
            y-=1
#            print(x, y, cnt)
            a[x][y] = cnt
            cnt+=1
#     y+=1
    for i in range(N) :
        for j in range(N) :
            print(a[j][i], end=' ')
        print()

def test() :
    N = int(input("input 1~4, 0 to exit\n"))
    F = [0, callmain, printfibo, lists, snail]
    while N :
        F[N]()
        N = int(input())

test()
