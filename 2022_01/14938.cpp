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

int n,m,r;
int t[102];
int a,b,l;
int ans;
int d[102];
vpii v[102];

void dijk(int x){
    priority_queue<pii, vpii, greater<pii>> pq;
    d[x] = 0;
    pq.push({0, x});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cost = cur.first;
        int idx = cur.second;

        if(d[idx] != cost) continue;

        for(int i=0; i<v[idx].size(); i++){
            int nc = v[idx][i].first;
            int nx = v[idx][i].second;
            if(d[nx] > cost + nc){
                d[nx] = cost + nc;
                pq.push({d[nx], nx});
            }
        }
    }
    //for(int i=1; i<=n; i++) cout << d[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;
    
    for(int i=1; i<=n; i++)
        cin >> t[i];
    
    for(int i=0; i<r; i++){
        cin >> a >> b >> l;
        v[a].push_back({l,b});
        v[b].push_back({l,a});
    }
    

    for(int i=1; i<=n; i++){
        fill(d, d+n+1, INT_MAX);
        int temp=0;

        dijk(i);
        
        for(int j=1; j<=n; j++)
            if(d[j] <= m) temp += t[j];

        ans = max(ans, temp);
    }
    
    cout << ans;
}
//10:09 ~45