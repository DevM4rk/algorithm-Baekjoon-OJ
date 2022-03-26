#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n,m;
vpii v[50001];
int d[50001];

void dijk(int a){
    d[a] = 0;

    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0,a});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int dist = cur.first;
        int x = cur.second;

        if(d[x] != dist) continue;

        for(int i=0; i<v[x].size(); i++){
            int ndist = v[x][i].first;
            int nx = v[x][i].second;
            if(d[nx] > dist + ndist){
                d[nx] = dist + ndist;
                pq.push({d[nx],nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});    
    }

    fill(d, d+n+1, 2e9);

    dijk(1);

    cout << d[n];
    
}
//2:01 ~ 2:14