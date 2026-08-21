import heapq

def solution(ability, number):
    answer = 0
    ab = []
    for a in ability:
        heapq.heappush(ab, a)
    
    #print(ab)

    for i in range(number):
        t1 = heapq.heappop(ab)
        t2 = heapq.heappop(ab)
        #print(t1,t2)
        tsum = t1+t2
        heapq.heappush(ab, tsum)
        heapq.heappush(ab, tsum)
        #print(ab)

    for a in ability:
        #print(a)
        answer += ab.pop()

    return answer

"""
2,3,7,10
5,5,7,10
10,10,7,10
"""