def solution(video_len, pos, op_start, op_end, commands):
    def cc(a):
        return int(a[:2])*60 + int(a[3:])
    vlen = cc(video_len)
    cur = cc(pos)
    opst = cc(op_start)
    opend = cc(op_end)
    
    if opst <= cur <= opend:
        cur = opend
    
    for com in commands:
        if com == "prev":
            cur -=10
            if cur < 0:
                cur = 0
        elif com == "next":
            cur +=10
            if cur> vlen:
                cur = vlen
        
        if opst <= cur <= opend:
            cur = opend
    
    print(cur//60 , cur%60)
    temp = cur//60
    temp2 = cur%60
    answer = f"{temp:02d}:{temp2:02d}"
    return answer
#1:22 16qns