def solution(targets):
    answer = 0
    
    targets.sort(key = lambda x : x[1])
    # for t in targets:
    #     print(t)
    
    st = 0
    end = 0
    for s, e in targets:
        if end <= s:
            print(end, s)
            st = s
            end = e
            answer+=1
            
        
    return answer