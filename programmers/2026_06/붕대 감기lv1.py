def solution(bandage, health, attacks):
    answer = 0
    maxhealth = health
    at=0
    cnt=0
    for i in range(1,attacks[-1][0] + 1):
        if attacks[at][0] == i:
            print(i)
            health-=attacks[at][1]
            at+=1
            cnt=0
            if health <= 0:
                return -1
        else:
            cnt+=1
            health+=bandage[1]
            if cnt == bandage[0]:
                cnt=0
                health+=bandage[2]
            if maxhealth < health:
                health = maxhealth
        
    return health