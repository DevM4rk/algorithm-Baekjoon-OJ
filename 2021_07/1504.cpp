#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()
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

int N,E,v1,v2, res = INF;
int sToV1, sToV2, V1ToV2, V1ToN, V2ToN;
int d[801];
vpii vp[801];

void dijk(int s){
    priority_queue<pii, vpii, greater<pii> > pq;
    fill(d, d+N+1, INF);
    d[s] = 0;    //시작점 자기자신은 0
    pq.push({0,s});   //K의 가중치, 정점

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
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> E;

    while(E--){
        int a, b, c;
        cin >> a >> b >> c;
        vp[a].push_back({c,b}); //재귀할때 알기 편하기 위해 가중치를 앞에 저장
        vp[b].push_back({c,a});
    }

    cin >> v1 >> v2;
        
	dijk(1);
	sToV1 = d[v1];
	sToV2 = d[v2];

	dijk(v1);
	V1ToV2 = d[v2];
	V1ToN = d[N];

	dijk(v2);
	V2ToN = d[N];

	res = min(res, sToV1 + V1ToV2 + V2ToN);
	res = min(res, sToV2 + V1ToV2 + V1ToN);
	if (V1ToV2 == INF || res == INF) cout << -1;
	else cout << res;
    
}

// start -> v1 -> v2 -> N , 
// start -> v2 -> v1 -> N 을 거쳐가는 두가지 경우를 모두 생각해줘야 함
//양방향이니 저장 반대로도 해줘야함

// 1 -> v1 다익
// 1 -> v2 다익     

// v1 -> v2 다익
// v2 -> v1 다익    - 둘 다 동일

// v1 -> N 다익
// v2 -> N 다익