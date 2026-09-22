import heapq
from collections import defaultdict

def solution(n, passages, records):
    answer = []

    # dist = [[1e9]*(n+1) for _ in range(n+1)]

    # weights = [[] for _ in range(n+1)]

    # for a, b, c in passages:
    #     weights[a].append((c, b))
    #     weights[b].append((c, a))

    # for i in range(1, n+1):
    #     dist[i][i] = 0
    #     pq = []
    #     heapq.heappush(pq, (0, i))
    #     while pq:
    #         d, x = heapq.heappop(pq)
    #         if dist[i][x] < d:
    #             continue

    #         for w, nx in weights[x]:
    #             if dist[i][nx] > d + w:
    #                 dist[i][nx] = d + w
    #                 heapq.heappush(pq, (dist[i][nx], nx))
    #     #print(dist[i])

    #플로이드와샬
    dist = [[1e9]*(n+1) for _ in range(n+1)]
    for i in range(1, n+1):
        dist[i][i] = 0

    for a, b, c in passages:
        if dist[a][b] > c:
            dist[a][b] = c
            dist[b][a] = c

    for k in range(1, n+1):
        for i in range(1, n+1):
            for j in range(1, n+1):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    for d in dist:
        print(d)


    cards = defaultdict(list)
    for rec in records:
        cards[rec[2]].append((rec[0], rec[1]))

    for key in cards:
        cards[key].sort()

    #print(cards)

    for card,li in cards.items():
        #print(card, li)

        prv = 0
        prtime = 0
        for time, v in li:
            if prv == 0:
                prv = v
                prtime = time
                continue

            #print(prv, v, prtime, time)
            if dist[prv][v] > time - prtime:
                #print(dist[prv][v], time - prtime)
                answer.append(card)
                break

            prv = v
            prtime = time

    return answer

if __name__ == "__main__":
    n1 = 6
    passages1 = [[1, 2, 6], [2, 3, 12], [1, 4, 10], [1, 5, 3], [3, 5, 2], [3, 6, 10], [4, 5, 5]]
    records1 = [[10, 1, 100000], [25, 2, 100000], [10, 4, 522224], [20, 3, 986666], [11, 6, 986666], [18, 1, 522224], [35, 3, 100000], [15, 5, 222222], [16, 5, 222222]]
    print(f"TC1 : {solution(n1, passages1, records1)}")
    print(": [100000, 986666]\n")

    n2 = 6
    passages2 = [[1, 2, 6], [2, 3, 12], [1, 4, 10], [1, 5, 3], [3, 5, 2], [3, 6, 10], [4, 5, 5]]
    records2 = [[0, 5, 222222], [1, 5, 222222], [9, 2, 222222], [0, 4, 500000], [5, 5, 500000], [7, 3, 500000], [17, 6, 500000]]
    print(f"TC2 : {solution(n2, passages2, records2)}")
    print(": [222222]\n")