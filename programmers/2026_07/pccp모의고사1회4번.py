import heapq

def solution(program):
    answer = [0] * 11
    for i,p in enumerate(program):
        p.append(i+1)
        
    program.sort(key = lambda x : (x[1], x[0]))
    
    time = program[0][1]
    i = 1
    q = []
    heapq.heappush(q, program[0])

    while q:
        v = heapq.heappop(q)
        
        answer[v[0]] += time - v[1]
        time += v[2]

        while 1:
            if i < len(program) and program[i][1] <= time:
                heapq.heappush(q, program[i])
                i+=1
            else:
                break

        if not q and i < len(program):
            heapq.heappush(q, program[i])
            time=program[i][1]
            i+=1



    answer[0] += time
    return answer