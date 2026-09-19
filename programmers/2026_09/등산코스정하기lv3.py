import heapq

def solution(n, paths, gates, summits):
    weight = [[] for _ in range(n+1)]
    
    # 빠른 탐색을 위해 set으로 변환
    gates_set = set(gates)
    summits_set = set(summits)
    
    # 그래프 연결 (w를 앞으로 두어 튜플 정렬 없이도 힙/최소값 판별이 쉽도록 함)
    for a, b, w in paths:
        weight[a].append((w, b))
        weight[b].append((w, a))
        
    dist = [1e18] * (n+1)
    pq = []
    
    # 모든 출발지(출입구)를 한 번에 큐에 넣고 시작 (다중 출발지 다익스트라)
    for g in gates:
        heapq.heappush(pq, (0, g))
        dist[g] = 0
        
    while pq:
        its, x = heapq.heappop(pq)
        
        # 이미 더 작은 intensity로 갱신된 적이 있다면 패스 (시간 초과 방지)
        if dist[x] < its:
            continue
            
        # 큐에서 꺼낸 곳이 산봉우리라면, 더 이상 다른 곳으로 이동하지 않음
        # (출입구 -> 산봉우리 단방향만 구하면 되기 때문)
        if x in summits_set:
            continue
            
        for w, nx in weight[x]:
            new_its = max(its, w)
            
            if dist[nx] > new_its:
                dist[nx] = new_its
                heapq.heappush(pq, (new_its, nx))
                
    summits.sort()
    
    ans_summit = 0
    ans_weight = 1e18
    
    for s in summits:
        if ans_weight > dist[s]:
            ans_summit = s
            ans_weight = dist[s]
            
    return [ans_summit, ans_weight]