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

int n,m,x,ans;
vpii v[1001];
int d[1001], t[1001];

void dijk(int idx){
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0,idx});
    d[idx] = 0;

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int ctime = cur.first;
        int cidx = cur.second;

        if(d[cidx] != ctime) continue;

        for(int i=0; i<v[cidx].size(); i++){
            int ntime = v[cidx][i].first;
            int nidx = v[cidx][i].second;
            if(d[nidx] > ctime + ntime){
                d[nidx] = ctime + ntime;
                pq.push({d[nidx], nidx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> x;
    
    for(int i=0; i<m; i++){
        int a,b,t; cin >> a >> b >> t;
        v[a].push_back({t,b});
    }

    for(int i=1; i<=n; i++){
        fill(d, d+n+1, INT_MAX);
        dijk(i);
        t[i] = d[x];
    }

    fill(d, d+n+1, INT_MAX);
    dijk(x);
    for(int i=1; i<=n; i++) t[i] = t[i] + d[i];

    cout << *max_element(t, t+n+1);

}
// 12:07 ~ 32