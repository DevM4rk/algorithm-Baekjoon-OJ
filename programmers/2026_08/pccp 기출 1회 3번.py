def solution(h1, m1, s1, h2, m2, s2):
    answer = 0
    s = 1
    m = 60
    h = 720 #sector hour in sec

    st = h1*3600 + m1*60 + s1
    end = h2*3600 + m2*60 + s2


    sts=61
    stm=61
    sth=61
    for time in range(st, end+1):
        if time == 43200 or time == 0:
            answer+=1
            sts=61
            stm=61
            sth=61
            continue

        nsts = time%60
        if sts >= 59 and nsts == 0:
            nsts = 60
        nstm = (time/60)%60
        #if stm >= 59 and nstm == 0:
        #    nstm = 60
        nsth = (time/720)%60
        #if sth >= 59 and nsth == 0:
        #    nsth = 60

        #59초면 초침은 59섹터 분침은 0섹터임
        if sts < stm and nstm <= nsts:
            answer+=1
            #print("분침",time, nsts, nstm)
        if sts < sth and nsth <= nsts:
            answer+=1
            #print("시침",time, nsts, nsth)

        sts = nsts%60
        stm = nstm%60
        sth = nsth%60

    
    return answer
    #17qns start
    #12시가아니면 아무리겹쳐있다해도 2번알람임 
    #1초당계산하니까 60섹터로나눔
    #분침은 60섹터로 나눠있음
    #시침은 12 * 5해야함
    """
    시침이 1섹터까지 도달하는데 걸리는 시간은?
    0시 ~ 12시까지있음
    초로하면
    60*60*12 = 43200초
    시침이 1섹터까지는 =720초 = 12분
    분침이 1섹터까지는 60초 = 1분
    초침이 1섹터까지 1초
    """