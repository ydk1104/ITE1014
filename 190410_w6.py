def readarticle() :
    f = open("article.txt", "r")
    print(f.read())
    f.close()

def countarticle() :
    f = open("article.txt", "r")
    ignore = [",", ".", "?", "!", "'", '"', "/", ":", "-", "\n", "[", "]"]
    line = "1"
    dic = {}
    while True :
        line = f.readline()
        if line == "" : break
        line = line.lower()
        for i in ignore :
            line = line.replace(i, "")
        A = line.split(" ")
        for i in A :
            if i == '' : continue
            if i in dic : dic[i]+=1
            else : dic[i] = 1
#    print(dic)
    for i in dic :
        print(i+":"+str(dic[i]))
    f.close()

def checkal(ch) :
    ch = ord(ch)
    if ch<ord('A') or ch>ord('z') : return 1
    if ch>ord('Z') and ch<ord('a') : return 1
    return 0

def cmp1(x, y) :
    if x[0] > y[0] : return 1
    return 0

def cmp2(x, y) :
    if x[1] > y[1] : return 1
    return 0

def sort(arr, cmp) :
    for i in range(len(arr)) :
        for j in range(i, len(arr)) :
            if cmp(arr[i], arr[j]) : arr[i],arr[j] = arr[j],arr[i];
    return arr;

def countalarticle() :
    f = open("article.txt", "r")
    count = []
    for i in range(26) :
        now = [chr(ord('A')+i), 0]
        count.append(now)
    for i in range(26) :
        now = [chr(ord('a')+i), 0]
        count.append(now)
    while True :
        line = f.readline()
        if line == "" : break
        for ch in line :
            if checkal(ch) : continue
            now = ord(ch)-ord('A')
            if now>25 : now = ord(ch)-ord('a')+26
            count[now][1] += 1
    sort(count, cmp1)
    for i in count :
        print(i[0] + ":" + str(i[1]))
    sort(count, cmp2)
    for i in count :
        print(i[0] + ":" + str(i[1]))
    f.close()

def image() :
    import imageio
    img = imageio.imread("carry_grant.jpg")
    print(img.shape)

def imagestatistics() :
    import imageio
    img = imageio.imread("carry_grant.jpg")
    sum = 0
    sum2 = 0
    count = []
    for i in range(256) : count.append(0)
    for i in range(img.shape[0]) :
        for j in range(img.shape[1]) :
            now = int(img[i][j])
            count[now]+=1
            sum += now
            sum2 += now * now
    total = img.shape[0] * img.shape[1]
    min = 0
    while count[min] == 0 : min+=1
    max = 255
    while count[max] == 0 : max-=1
    now = 0
    nowtotal = 0
    while nowtotal<total/2 :
        nowtotal += count[now]
        now+=1
    if nowtotal == total/2 :
        nowright = now+1
        while cnt[nowright] : nowright+=1
        mid = (now+nowright)/2
    else : mid = now
    print("min =", min,"\nmax =", max, "\nmid =", mid);
    mean = sum/total
    var = sum2/total - mean*mean
    print("mean =",mean, "\nvar =",var)
    print("bih" + " "*10 + "count" + " "*10 + "percentage(%)")
    for i in range(256) :
        print(i,":"," "*10,count[i]," "*10,"%.4f"%(100*count[i]/total))

def hist_eq():
    import imageio
    img = imageio.imread("HDR.jpg");
    count = []
    for i in range(256) : count.append(0)
    for i in range(img.shape[0]) :
        for j in range(img.shape[1]) :
            now = int(img[i][j])
            count[now]+=1
    total = img.shape[0] * img.shape[1]
    nowtotal = 0
    print(total)
    print("bih" + " "*10 + "count" + " "*10 + "percentage(%)")
    for i in range(256) :
        print(i,":"," "*10,count[i]," "*10,"%.4f"%(100*count[i]/total))
        nowtotal += count[i]
        count[i] = int(nowtotal*255/total)
        print(count[i])
    count2 = []
    for i in range(256) : count2.append(0)
    for i in range(img.shape[0]) :
        for j in range(img.shape[1]) :
            now = img[i][j]
            img[i][j] = count[now]
            now = img[i][j]
            count2[now]+=1
    print("bih" + " "*10 + "count" + " "*10 + "percentage(%)")
    for i in range(256) :
        print(i,":"," "*10,count2[i]," "*10,"%.4f"%(100*count2[i]/total))
    imageio.imwrite("picture_out.jpg", img)
    print("End")
    

def test() :
    arr = [readarticle, countarticle, countalarticle, image, imagestatistics, hist_eq]
    N = int(input("번호를 입력해주세요, 끝내려면 0번을 입력해주세요"))
    while N :
        arr[N-1]()
        N = int(input("번호를 입력해주세요, 끝내려면 0번을 입력해주세요"))
test()
