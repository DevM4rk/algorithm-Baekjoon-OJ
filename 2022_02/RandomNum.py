import random

print("Print RandomNum 97 ~ 109.9")
print("Enter key to continue...")

idx=0
while 1 :
    s = input()
    idx+=1
    print("--",idx)
    for i in range(8) :
        a = random.uniform(97, 109.9)
        print("{:.1f}".format(a).ljust(5), end='  ')
    print()