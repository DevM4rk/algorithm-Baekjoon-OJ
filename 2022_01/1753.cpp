#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int v,e,k;
int d[20002];
vpii vtp[20002];

void solve(){
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0,k});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cw = cur.first;
        int cv = cur.second;

        //먼저들어가서 뒤로 밀린 애들도 많으니 제거해주기, 안해도 되지만 시간 단축
        if(d[cv] != cw) continue;

        for(int i=0; i<vtp[cv].size(); i++){
            int nw = vtp[cv][i].first;
            int nv = vtp[cv][i].second;
            if(d[nv] <= cw + nw) continue;   //기존에 계산된 것이 내가 거쳐온 가중치 + 가르키는 가중치보다 작으면 패스
            d[nv] = cw + nw;
            pq.push({d[nv],nv});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> v >> e >> k;

    for(int i=0; i<e; i++){
        int a,b,c; 
        cin >> a >> b >> c;
        vtp[a].push_back({c,b}); // a->b로가는 가중치 c
    }

    fill(d,d+v+1, INT_MAX);
    d[k]=0;

    solve();

    for(int i=1; i<=v; i++){
        if(d[i]==INT_MAX) cout << "INF" << "\n";
        else cout << d[i] << "\n";
    }
}