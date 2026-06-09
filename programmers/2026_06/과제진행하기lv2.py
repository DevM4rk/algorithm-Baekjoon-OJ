def solution(plans):
    answer = []
    save = []
    plans.sort(key=lambda x:x[1])
    for name, st, pt in plans:
        h, m = map(int, st.split(":"))
        st = h*60 + m

        print(name, st, pt)
        if save:
            pn, pst, ppt = save[-1]
            t = st - pst

        while 1:
            if save:
                pn, pst, ppt = save[-1]
                if ppt <= t:

                    print("1",pn, pst, ppt, t)
                    t -= ppt
                    save.pop()
                    answer.append(pn)
                    #print(t, pn)
                else:
                    ppt -= t
                    save[-1][2] = ppt
                    print("2",pn, pst, ppt)
                    break
            else:
                break

        save.append([name,int(st),int(pt)])

    for n, s, p in save[::-1]:
        answer.append(n)
    return answer
