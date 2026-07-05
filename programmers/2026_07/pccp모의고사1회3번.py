def solution(queries):
    answer = []
    
    def find(n,p):
        print(n,p)
        if n == 1 :
            return "Rr"

        f = find(n-1, (p-1)//4+1)
        bean = ["RR","Rr","Rr","rr"]

        if f == "RR" or f == "rr":
            return f
        else:
            return bean[p%4-1]


    for n,p in queries:
        answer.append(find(n,p))

    return answer
    """
    n = 2 RR Rr Rr rr
    n = 3  p//4
    """