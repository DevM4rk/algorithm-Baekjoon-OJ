def cal(t):
    return int(t[0:2])*60 + int(t[3:5])  

def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    vlen = cal(video_len)
    pos = cal(pos)
    st = cal(op_start)
    end = cal(op_end)
    if st <= pos <= end:
        pos = end
    print(st, pos, end)
        
    for cmd in commands :
        if cmd == "next":
            pos += 10
            if vlen < pos:
                pos = vlen
        if cmd == "prev":
            pos -= 10
            if pos < 0:
                pos = 0
    
        if st <= pos < end:
            pos = end
    
    print(pos)
    
    minute = str(pos // 60)
    second = str(pos % 60)

    if len(minute) == 1:
        minute = "0" + minute

    if len(second) == 1:
        second = "0" + second

    return minute + ":" + second
