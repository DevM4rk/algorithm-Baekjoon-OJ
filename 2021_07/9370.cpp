#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define MAX 2001
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

int n;
int d[MAX], t[101], dist_s[101], dist_h[101], dist_g[101];
vpii vp[MAX];

void dijk(int s){
    priority_queue<pii, vpii, greater<pii> > pq;
    fill(d, d+n+1, INF);
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; 
    cin >> T;
    
    while(T--){
        int m,tt, s,g,h; 
        cin >> n >> m >> tt;
        cin >> s >> g >> h;

        while(m--){
            int a,b,d;
            cin >> a >> b >> d;
            vp[a].push_back({d,b}); //재귀할때 알기 편하기 위해 가중치를 앞에 저장
            vp[b].push_back({d,a});
        }

        for(int i=0; i<tt; i++) cin >> t[i];
        sort(t,t+tt);   //오름차순 출력을 위해


        dijk(s);
        for(int i=0; i<tt; i++) dist_s[i] = d[t[i]];    //save d[t[i]]
        int s_g = d[g];
        int s_h = d[h];

        dijk(h);
        for(int i=0; i<tt; i++) dist_h[i] = d[t[i]];
        int h_g = d[g];

        dijk(g);
        for(int i=0; i<tt; i++) dist_g[i] = d[t[i]];


        for(int i=0; i<tt; i++){
            int ans = min(s_h + h_g + dist_g[i], s_g + h_g + dist_h[i]);
            if( ans <= dist_s[i]) cout << t[i] << " ";
        }
        cout << endl;

        // dist, t, vp 초기화
        for(int i=1; i<=n; i++) vp[i].clear();
        fill(t, t+tt, 0);
        fill(dist_s, dist_s+tt, 0);
        fill(dist_h, dist_h+tt, 0);
        fill(dist_g, dist_g+tt, 0);
    }
}

/*

두가지 경우 생각해야댐
s -> g -> h -> t
s -> h -> g -> t

g -> h 값은 입력에서 주어지기 때문에

s -> g , h -> t
s -> h , g -> t 를 계산,

점선은 목지 후보들 중 적어도 1개로 향하는 최단 경로의 일부이다. 
따라서 예제의 경우 목적지 5로가는 경우의 수가 점선을거쳐가는경우보다 더 빠르므로 목적지 5는 아니다.
if (순수d[i] > 점선거쳐가는d[i])  출력

*/