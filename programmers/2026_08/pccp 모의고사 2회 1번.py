dx = [0,1,0,-1]
dy = [1,0,-1,0]

def solution(command):
    answer = [0,0]
    init = 0

    for c in command:
        if c == 'G':
            answer[0] += dx[init]
            answer[1] += dy[init]
            #print(answer)

        elif c == "B":
            
            answer[0] -= dx[init]
            answer[1] -= dy[init]
            #print(answer)

        elif c == "R":
            init+=1
            if init >= 4:
                init = 0

        else: # L
            init-=1
            if init < 0:
                init = 3
        

    return answer