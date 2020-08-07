import random

sum = 0
for i in range(1,51) :
    customer = random.randrange(5,51)
    if 5 <= customer <= 15 : 
        check = "O"
        sum += 1
    else : 
        check = " "
    print("[{0}] {1}번째 손님 (소요시간 : {2}분)".format(check,i,customer))
print("총 탑승 객 %d" % sum )
