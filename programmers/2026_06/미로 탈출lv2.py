from collections import deque

def solution(maps):
    answer = -1
    n = len(maps)
    m = len(maps[0])
    vis = [[0]*m for _ in range(n)]
    
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]
    
    def bfs(x,y,cnt):
        lever = 1
        nonlocal answer
        q = deque()
        vis[x][y] = 1
        q.append((x,y,cnt))
        
        while q:
            x,y,cnt = q.popleft()
            print(x,y,cnt)
            
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx <0 or ny <0 or nx >= n or ny >= m or maps[nx][ny] == "X":
                    continue
                    
                if lever == 2 and maps[nx][ny] == "E":
                    answer = cnt+1
                    return 1
                elif lever == 1 and maps[nx][ny] == "L":
                    lever = 2
                    vis[nx][ny] = 2
                    q.clear()
                    q.append((nx,ny,cnt+1))
                    break
                elif vis[nx][ny] != lever:
                    vis[nx][ny] = lever
                    q.append((nx,ny,cnt+1))

    
    for i in range(n):
        for j in range(m):
            if maps[i][j] == "S":
                bfs(i,j,0)
    
    return answer
"""
4:04 ~ 4:40
출구칸 지나갈수있음
lever 변수하나둬서 체크하기
"""