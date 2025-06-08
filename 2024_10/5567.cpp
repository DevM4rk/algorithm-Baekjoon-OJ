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

vi v[501];
vi vis(501);
int n,m,ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    vis[1] = 1;
    q.push(1);

    while(!q.empty()){
        auto x = q.front(); q.pop();
        
        for(int i=0; i<v[x].size(); i++){
            auto nx = v[x][i];
            if( vis[nx] > 0 ) continue;
            vis[nx] = vis[x]+1;
            q.push(nx);
            
        }
    }
    //for(auto a : vis) cout << a;

    for(auto a : vis) if(a==2 || a==3) ans++;
    cout << ans;
}