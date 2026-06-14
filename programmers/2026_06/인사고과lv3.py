def solution(scores):
    answer = 1
    ma,mb = scores[0]
    msum = ma + mb
    d = {}
    scores.sort(key = lambda x : (-x[0], x[1]))
    #print(scores)
    
    max_b = 0
    for a,b in scores:
        max_b = max(max_b,b)
        if max_b > b:
            continue
        
        if a > ma and b > mb:
            return -1
        elif a < ma and b < mb:
            continue
        else:
            sum = a+b
            if sum not in d:
                d[sum] = 1
            else:
                d[sum]+=1
    
    d2 = sorted(d.items(), reverse= True)
    #print(d2)
    for k,v in d2:
        if msum < k :
            answer += v
        else:
            break
    
    return answer

"""
완호보다 두개다 큰놈있으면 -1
하나라도 높으면 둘의 d[합산점수] += 1
두개다 낮으면 넘어감

가장중요한 것은 다른 사원의 두 점수가 낮으면 박탈임
그럼 b의 숫자 중 가장 높았던 점수를 저장해서 비교하기

"""