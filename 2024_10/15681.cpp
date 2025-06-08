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

int n,r,q;
vi v[100001];
vi vis(100001);

int dfs(int x){
    vis[x] = 1;

    for(int i=0; i<v[x].size(); i++){
        int nx = v[x][i];
        if(vis[nx]>0) continue;
        vis[x] += dfs(nx);
    }
    return vis[x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> r >> q;
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);        
    }

    dfs(r);

    while(q--){
        int u; cin >> u;
        cout << vis[u] << endl;
    }
}