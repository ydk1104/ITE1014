def printstar(blank, star) :
    print(' '*blank + '*'*star)

print("test1")
N = int(input("Input dan.\n"))

print("*"*10 + str(N) + "*"*10)
for i in range(1, 10) :
    print(str(N) + "*" + str(i) + "=" + str(N))
print("*"*21)

print("test2")
line = 1
while(line<=5) :
#    blank = 5-line
#    while(blank>0) :
#        print(" ", end='')
#        blank-=1
#    i = 1
#    while(i<=line*2-1) :
#        print("*", end='')
#        i+=1
#    print()
    printstar(5-line, line*2-1)
    line+=1

print("test3")
line = 5
while(line>1) :
    blank = 5-line
    while(blank>0) :
        print(" ", end='')
        blank-=1
    i = 1
    while(i<=line*2-1) :
        print("*", end='')
        i+=1
    print()
    line-=1
while(line<=5) :
    blank = 5-line
    while(blank>0) :
        print(" ", end='')
        blank-=1
    i = 1
    while(i<=line*2-1) :
        print("*", end='')
        i+=1
    print()
    line+=1

    
print("test4")
import time
test = 200
first = time.time()
for i in range(test) :
  print("*", end='')
second = time.time()
s = ""
for i in range(test) :
  s += "*"
print(s)
third = time.time()
print(second - first)
print(third - second)
