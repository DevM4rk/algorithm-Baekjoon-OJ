def solution(points, routes):
    answer = 0
    
    dict = {}
    
    for route in routes:
        rt = route[0]-1
        sx, sy = points[rt]
        sec = 0
        if (sec,sx,sy) in dict:
            dict[(sec,sx,sy)]+=1
        else:
            dict[(sec,sx,sy)]=1
            
        for r in route[1:]:
            ex, ey = points[r-1]
            
            while not (sx == ex and sy == ey):
                if sx < ex: sx +=1
                elif sx > ex: sx-=1
                elif sy < ey: sy+=1
                elif sy > ey: sy-=1
                sec+=1
                
                if (sec,sx,sy) in dict:
                    dict[(sec,sx,sy)]+=1
                else:
                    dict[(sec,sx,sy)]=1
    
            
            sx = ex
            sy = ey
    
    for d in dict.items():
        #print(d)
        if d[1] > 1:
            answer+=1
    return answer
#36 30qns?