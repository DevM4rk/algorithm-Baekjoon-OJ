def MyExpMod(a : int, n : int, m : int) -> int:
    return a**n % m

def MyInvMod(a : int, m : int) -> int:
    i = 1
    while True :
        if ((a % m) * i) % m == 1 : 
            return i
        i+=1

a = int(input("a : "))
n = int(input("n : "))
m = int(input("m : "))

print("MyExpMod : %d" % MyExpMod(a,n,m))
print("MyInvMod : %d" % MyInvMod(a,m))