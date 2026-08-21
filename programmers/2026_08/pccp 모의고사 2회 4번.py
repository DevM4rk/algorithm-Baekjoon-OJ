from collections import deque

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def solution(n, m, hole):
    n, m = m, n
    vis = [[[0]*2 for _ in range(m)] for _ in range(n)]
    board = [[0]*m for _ in range(n)]

    for h in hole:
        y,x = h
        board[x-1][y-1] = 1

    q = deque()
    q.append((0,0,0,0))
    vis[0][0][0]=1
    vis[0][0][1]=1

    while q:
        x,y,jump,cnt = q.popleft()
        #print(x,y,jump,cnt)
        if x == n-1 and y == m-1:
            #print("bye1")
            return cnt

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                if  vis[nx][ny][jump] == 0:
                    vis[nx][ny][jump] = 1
                    q.append((nx,ny,jump,cnt+1))
                    #if jump==1 and vis[nx][ny][0] <= cnt+1:



        if jump == 0 :
            for i in range(4):
                nx = x + dx[i]*2
                ny = y + dy[i]*2
                if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0:
                    if  vis[nx][ny][1] == 0:
                        vis[nx][ny][1] = 1
                        q.append((nx,ny,1,cnt+1))
                                       
    return -1
"""
1:31~ 
"""