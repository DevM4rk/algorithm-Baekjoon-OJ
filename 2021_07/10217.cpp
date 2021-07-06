#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define INF 987654321

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tp;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int T, N, M, K, u,v,c,d;
int dp[101][10001], ans;  //dp[i][j] : j 비용으로 i 공항까지 가는 최소 시간
vector<tp> vt[101];

void dijk(){
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    dp[1][0] = 0;
    pq.push({0,1,0});

    while(!pq.empty()){
        int time = get<0>(pq.top());
        int now = get<1>(pq.top());
        int money = get<2>(pq.top());

        pq.pop();

        if(dp[now][money] != time) continue;

        for(int i=0; i<vt[now].size(); i++){    //시간,도착,비용
            int ntime = get<0>(vt[now][i]) + time;
            int next = get<1>(vt[now][i]);
            int nmoney = get<2>(vt[now][i]) + money;

            if(nmoney > M) continue;

            if(dp[next][nmoney] <= ntime) continue;

			for (int j = nmoney; j <= M; j++) {
				if (dp[next][j] > ntime) {
					dp[next][j] = ntime;
				}
			}
            pq.push({ntime,next,nmoney});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--){
        cin >> N >> M >> K;

        for(int i=1; i<=N; i++){
            vt[i].clear();
            
            for(int j=0; j <= 10000; j++)
                dp[i][j] = INF;
        }
        ans = INF;

        while(K--){
            cin >> u >> v >> c >> d;    //출발,도착,비용,시간
            vt[u].push_back({d,v,c});   //시간 먼저
        }

        dijk();

        for (int i = 1; i <= M; i++) 
			ans = min(ans, dp[N][i]);

		if (ans == INF) cout << "Poor KCM" << '\n';
		else cout << ans << '\n';
    }
}
//비용보단 최단거리우선
//dp[i][j] : j 비용으로 i 공항까지 가는 최소 시간
