#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define MAX 20001
#define INF 987654321

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int V,E,K,u,v,w;
int d[MAX];
vpii vp[MAX];

void solve(){
    priority_queue<pii, vpii, greater<pii> > pq;
    d[K] = 0;    //시작점 자기자신은 0
    pq.push({0,K});   //K의 가중치, 정점

    while(!pq.empty()){     
        int dist = pq.top().first; // 가중치
        int idx = pq.top().second; // 정점
        pq.pop();   //가중치가 가장 작은 간선을 꺼내서 저장 후 꺼냄
        
        if (d[idx] != dist) continue;   //다르다면, 저장할 때보다 더 짧은 경로를 찾은 것이므로

        for(int i=0; i<vp[idx].size(); i++){    //연결 되어있는 간선을 모두 돌음
            int cost = vp[idx][i].first;
            int next = vp[idx][i].second;
            
            if(d[next] > dist + cost){      //현재 저장된 최단거리보다 dist+cost의 값이 더 작으면 갱신
                d[next] = dist + cost;
                pq.push({d[next], next});   //더 짧은 길을 찾기 위해 pq에 추가
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E >> K;

    while(E--){
        cin >> u >> v >> w; //정점 간선 가중치
        vp[u].push_back({w, v});
    }
    fill(d, d+V+1, INF);

    solve();

    for(int i=1; i<=V; i++){
        if(d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << endl;
    }
}//1753

/*

1 (2,2) (3,3)
2 (3,4) (4,5)
3 (4,6)
5 (1,1)

pq(0,0)

d
0 inf inf inf inf	

0  2  inf inf inf	    pq(2,2)

0  2   3  inf inf      	pq(3,3)

pq(2,2)

0  2   3   7  inf      	pq(5,4)

*/