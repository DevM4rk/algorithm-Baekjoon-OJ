#각 번호의 레일마다 연결 가능한 입구 부분, 다음레일에 어떤게 올지 아구 맞추는데에 쓰임
rail = [[],             
        [(0,-1),(0,1)], #1
        [(-1,0),(1,0)], #2
        [(-1,0),(1,0),(0,-1),(0,1)],
        [(0,-1),(-1,0)],
        [(-1,0),(0,1)],
        [(0,1),(1,0)],
        [(0,-1),(1,0)]
       ]

def solution(grid):
    answer = 0
    n=len(grid)
    m=len(grid[0])
    vis = [[0]*m for _ in range(n)] # 3번레일때문에 2가 되어야 방문한것으로처리, 3번레일은 총 두번 들려야함

    def dfs(x,y,cur_node,px,py):
        nonlocal answer
        if x == n-1 and y == m-1 :
            
            for i in range(n):
                for j in range(m):
                    if 0 < grid[i][j] <= 7 and vis[i][j] != 2:
                        return

            answer+=1
            return
        
        for dx,dy in rail[cur_node]:
            nx = x + dx
            ny = y + dy
            if 0 <= nx < n and 0 <= ny < m and vis[nx][ny] != 2 and grid[nx][ny] != -1 :
                if nx == px and ny == py:   #바로 직전에 왔던레일이면 패스
                    continue
                    
                #레일이 이미 필드(그리드)에 존재하는경우
                if grid[nx][ny] != 0 :
                    for rx,ry in rail[grid[nx][ny]]:    # 다음 레일에 어떤걸 둘지
                        if dx+rx == 0 and dy+ry==0:     # 더했을때 0이되면 아구가 맞음
                            
                            if grid[nx][ny] == 3:
                                vis[nx][ny]+=1          # 3번레일은 두번 거쳐야함
                                if (rx == 0 and ry == 1) or (rx == 0 and ry == -1):
                                    dfs(nx,ny,1,x,y)        # 들어온 방향대로만 탐색, 문제조건임
                                else:
                                    dfs(nx,ny,2,x,y)
                                vis[nx][ny]-=1
                            else:
                                vis[nx][ny]=2
                                dfs(nx,ny,grid[nx][ny],x,y)
                                vis[nx][ny]=0
                else :
                    for k in range(8):
                        for rx,ry in rail[k]:
                            if dx+rx == 0 and dy+ry==0:
                                
                                if k == 3:
                                    vis[nx][ny]+=1          # 3번레일은 두번 거쳐야함
                                    grid[nx][ny]=k          # 레일 설치는 3번으로해야 다른 레일에서 탐색할때 제대로 알수있음
                                    if (rx == 0 and ry == 1) or (rx == 0 and ry == -1):
                                        dfs(nx,ny,1,x,y)        # dfs넘기는건 들어온 방향대로 나가야 하기 때문에 1또는2번레일로 방향을 잡아줌
                                    else:
                                        dfs(nx,ny,2,x,y)
                                    vis[nx][ny]-=1
                                    grid[nx][ny]=0

                                else:
                                    vis[nx][ny]=2
                                    grid[nx][ny]=k
                                    dfs(nx,ny,grid[nx][ny],x,y)
                                    vis[nx][ny]=0
                                    grid[nx][ny]=0
    
    vis[0][0] = 2
    dfs(0,0,1,0,0)
    return answer