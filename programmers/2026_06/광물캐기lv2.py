def solution(picks, minerals):
    q,w,e = picks
    sum = q+w+e
    answer = 0
    a=len(minerals)
    if sum*5 <= len(minerals):
        a = sum*5
    print(a)
    board = [minerals[i:i+5] for i in range(0, a, 5)]
    m_cnt = [[0] * 3 for _ in range(a//5 +1)]
    
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == "diamond":
                m_cnt[i][0] +=1
            if board[i][j] == "iron":
                m_cnt[i][1] +=1
            if board[i][j] == "stone":
                m_cnt[i][2] +=1
    
    m_cnt.sort(key = lambda x : (-x[0], -x[1], -x[2]))
    
    for m in m_cnt:
        print(m)
        
        cnt = 0
    for i, p in enumerate(picks):
        for _ in range(p):
            if cnt >= len(board):
                break
                
            d,ir,s = m_cnt[cnt]
            
            if i == 0:
                answer += d + ir + s
            if i == 1:
                answer += d*5 + ir + s
            if i == 2:
                answer += d*25 + ir*5 + s
            
            cnt+=1
        

    return answer

"""
5개씩 끊고, 다이아 순으로 정렬
"""