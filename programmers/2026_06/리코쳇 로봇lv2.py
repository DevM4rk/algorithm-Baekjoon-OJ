from collections import deque

dx = [0,0,-1,1]
dy = [1,-1,0,0]

def solution(board):
    answer = 0
    n = len(board)
    m = len(board[0])
    st = None
    vis = [[1000]* 101 for _ in range(101)]
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == "R":
                st = i,j
                break
                
    q = deque()
    vis[st[0]][st[1]]=0;
    q.append((st[0],st[1],0))
    
    while q:
        x, y, cnt = q.popleft()
        #print(x,y,cnt,vis[x][y])
        
        if board[x][y] == "G":
            return cnt
        
        if cnt > vis[x][y]:
            continue
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            while 1:
                if nx < 0 or nx >= n or ny < 0 or ny >= m or board[nx][ny] == "D":
                    nx -= dx[i]
                    ny -= dy[i]
                    break
                else:
                    nx += dx[i]
                    ny += dy[i]
            if cnt < vis[nx][ny]:
                vis[nx][ny] = cnt+1
                q.append((nx,ny,cnt+1))
                
    
    return -1
"""

"""