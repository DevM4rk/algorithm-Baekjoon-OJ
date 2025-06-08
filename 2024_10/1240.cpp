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

int n,q,ex, ans;
vpii v[1001];
vi vis(1001);

void dfs(int x,int cnt){
    vis[x] = 1;
    // cout << x << cnt << endl;

    if(x == ex){
        ans = cnt;
        return;
    }

    for(int i=0; i<v[x].size(); i++){
        auto [nx,def] = v[x][i];
        if(vis[nx]>0) continue;

        dfs(nx,cnt+def);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> q;
    for(int i=0; i<n-1; i++){
        int a,b,c; cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});        
    }


    while(q--){
        int a; cin >> a >> ex;
        dfs(a,0);

        cout << ans << endl;
        vis = vi(1001);
    }
    
}