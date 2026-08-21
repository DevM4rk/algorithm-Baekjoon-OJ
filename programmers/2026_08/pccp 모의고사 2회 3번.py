from collections import deque

def solution(menu, order, k):
    answer = 0
    time = -k
    q = deque()
    end=0
    for i in range(len(order)):
        time += k
        end = max(time,end) + menu[order[i]]

        while q and q[0]<=time:
            q.popleft()

        q.append(end)

        answer = max(answer, len(q))
        



    return answer

"""
첫손님 큐에 넣어 
몇초인지와 걸리는시간

"""