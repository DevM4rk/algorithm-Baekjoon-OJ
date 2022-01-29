#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
vector<pii> v[201];
int sdist[201];
int adist[201];
int bdist[201];
int n,s,a,b;

void dijk(int x, int arr[201]){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    arr[x] = 0;
    pq.push({0,x});
    
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cost = cur.first;
        int idx = cur.second;
        
        if(arr[idx] != cost) continue;
        
        for(auto [ncost, nidx] : v[idx]){
            if(arr[nidx] > cost + ncost){
                arr[nidx] = cost + ncost;
                pq.push({arr[nidx], nidx});
            }
        }
    }
}

int solution(int nn, int ss, int aa, int bb, vector<vector<int>> fares) {
    int ans = 0;
    n=nn;s=ss;a=aa;b=bb;
    fill(adist, adist+n+1, INT_MAX);
    fill(sdist, sdist+n+1, INT_MAX);
    fill(bdist, bdist+n+1, INT_MAX);

    for(auto f : fares){
        v[f[0]].push_back({f[2],f[1]});
        v[f[1]].push_back({f[2],f[0]});
    }

    
    dijk(a, adist);
    dijk(s, sdist);
    dijk(b, bdist);
    // for(int i=1; i<=n; i++) cout << sdist[i] << " ";
    // cout << endl;
    // for(int i=1; i<=n; i++) cout << adist[i] << " ";
    // cout << endl;
    // for(int i=1; i<=n; i++) cout << bdist[i] << " ";
    // cout << endl;

    ans = INT_MAX;
    for(int i=1; i<=n; i++){
        if(sdist[i]==INT_MAX || adist[i]==INT_MAX || bdist[i]==INT_MAX) continue;
        ans = min(ans, sdist[i]+adist[i]+bdist[i]);

    }
    return ans;
}
/*
9:45 ~ 11:0
A를 다익스트라 하고,B로가는 제일 짧은 구간의 노드들을 체크함
S를 다익스트라하고 위에서 구한 것 노드로 가는 것중 (최소값 + A->B의 값) 과 (S->A + S->B) 비교
68점

좀만 더 생각하면 , 모든 노드를 돌아보며 각각가는길과 한노드를 거쳐가는길 중 최소값을 구하면 더 빠름

**/