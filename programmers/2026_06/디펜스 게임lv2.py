import heapq

def solution(n, k, enemy):
    answer = 0
    heap = []
    m =0
    for e in enemy:
        #print(heap)
        if 0 < k:
            heapq.heappush(heap, e)     
            k -= 1
            answer+=1
            continue
        if heap[0] < e:
            x = heapq.heappop(heap)
            n-=x
            heapq.heappush(heap, e)     
        else :
            n -= e
            
        if n < 0 :
            break
        answer+=1

        
    return answer
"""
12:30
2 4 4 
2< 5
2 »©°í 5³Ö±â
2 > 1


"""