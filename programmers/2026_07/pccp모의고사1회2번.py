def solution(ability):
    answer = 0
    stud = len(ability)
    kind = len(ability[0])
    vis = [0]*11
    
    def dfs(x, sum):
        nonlocal answer
        #print(x,sum)
        if x == kind:
            answer = max(answer,sum) 
            return
        
        for i in range(stud):
            if vis[i] == 1:
                continue

            vis[i] = 1
            dfs(x+1, sum + ability[i][x])
            vis[i] = 0

    
    dfs(0 ,0)

    return answer