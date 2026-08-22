def solution(diffs, times, limit):
    answer = 1000000000000
    
    st = min(diffs)
    end = max(diffs)
    
    while st <= end:
        mid = (st + end+1) //2
        sum=times[0]
        #print(st, end, mid)
    
        for i in range(len(diffs)):
            if i == 0: continue
            
            if diffs[i] <= mid:
                sum += times[i]
            else:
                d = diffs[i] - mid
                sum += d * (times[i-1] + times[i]) + times[i]
        #print(sum)
        if sum <= limit:
            end = mid-1
            answer = min(answer, mid)
        else:
            st=mid+1
        
            
    
    return answer

#2tl~ 22