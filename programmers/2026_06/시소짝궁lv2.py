def solution(weights):
    answer = 0
    d = {}
    num = [0] * 1001
    
    weights.sort()
    
    for i, w in enumerate(weights):
        for j in range(2,5):
            t = w
            t *= j
            if t in d:
                answer += d[t] - num[w]
                d[t]+=1
            else:
                d[t]=1
        
        answer += num[w]
        num[w]+=1
    
    
    return answer