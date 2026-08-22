dx = [0,0,-1,1]
dy = [-1,1,0,0]

def solution(maze):
    answer = 999
    n = len(maze)
    m = len(maze[0])
    #print(n,m)
    
    info = [(0,0)]*5
    for i in range(n):
        for j in range(m):
            if maze[i][j] == 1:
                info[1] = (i,j)
            elif maze[i][j] == 2:
                info[2] = (i,j)
            elif maze[i][j] == 3:
                info[3] = (i,j)
            elif maze[i][j] == 4:
                info[4] = (i,j)

    rvis = [[0]*m for _ in range(n)]
    bvis = [[0]*m for _ in range(n)]
    #print(vis)
    
    rvis[info[1][0]][info[1][1]] = 1
    bvis[info[2][0]][info[2][1]] = 1
    rfinish = 0
    bfinish = 0
    
    def dfs(rxy, bxy, cnt):
        nonlocal answer,rfinish, bfinish
        rx, ry = rxy
        bx, by = bxy
        
        if rxy == info[3] and bxy == info[4]:
            answer = min(answer, cnt)
            #print("success")
            return
        
        for i in range(4):
            nrx = rx + dx[i]
            nry = ry + dy[i]
            nbx=0
            nby=0
            if (0<= nrx < n and 0 <= nry < m and maze[nrx][nry] != 5 and rvis[nrx][nry] == 0) or rfinish >0:
                check = False
                for j in range(4):
                    nbx = bx + dx[j]
                    nby = by + dy[j]
                    if check == True:
                        continue
                    if (0<= nbx < n and 0 <= nby < m and maze[nbx][nby] != 5 and bvis[nbx][nby] == 0) or bfinish >0:
                        
                        if rfinish > 0 :
                            nrx, nry = info[3]
                        if bfinish > 0 :
                            check = True
                            nbx, nby = info[4]
                            
                        if (nrx == nbx and nry == nby) or ((rx == nbx and ry == nby) and (bx == nrx and by == nry)):
                            continue
                            
                        rvis[nrx][nry] += 1
                        bvis[nbx][nby] += 1
                        
                        if (nrx,nry) == info[3]:
                            rfinish +=1
                        if (nbx,nby) == info[4]:
                            bfinish +=1
                            
                        #if bfinish > 0:    
                        #    print((nrx,nry),rfinish, (nbx,nby),bfinish, cnt+1)
                        dfs((nrx,nry),(nbx,nby),cnt+1)
                        
                        if rfinish > 0:
                            rfinish -=1
                        if bfinish > 0:
                            bfinish -=1
                        
                        rvis[nrx][nry] -= 1
                        bvis[nbx][nby] -= 1
    
    
    dfs(info[1], info[2], 0)
    
    if answer == 999:
        return 0
    return answer
#10 12~ 11:07 80Á¡
#1->3  2->4