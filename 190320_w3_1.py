N = int(input())
i = N-1
while(i>0) :
    print(" "*i + "*", end='')
    if(i!=N-1) : print(" "*(2*(N-i)-3) + "*")
    else : print()
    i=i-1
print("*"*(2*N-1))
