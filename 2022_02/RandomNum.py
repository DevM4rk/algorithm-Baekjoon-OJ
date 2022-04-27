import random

print("Print RandomNum Program")

while 1 :
    print("\n(If you want to print from 10, enter 10)")
    print("Set minimum number : ", end = '')
    MIN = float(input())

    print("\n(If you want to print up to 19.9, enter 20)")
    print("Set maximum number : ", end = '')
    MAX = float(input())
    MAX = MAX - 0.1

    if MIN < MAX :
        break
    else :
        print("\nError \n- {} ~ {} is impossible.".format(MIN,MAX))
        print("- Please enter the minimum number less than the maximum number.")

print("\nSetting complete!!")
print("Print RandomNum {} ~ {}".format(MIN,MAX))
print("Enter key to continue...")

idx=0
while 1 :
    s = input()
    idx+=1
    print("--",idx)
    for i in range(8) :
        a = random.uniform(MIN, MAX)
        print("{:.1f}".format(a).ljust(5), end='  ')
    print()