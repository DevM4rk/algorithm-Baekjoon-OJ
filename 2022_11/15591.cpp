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

vpii dist[5001];
int vis[5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N,Q; cin >> N >> Q;
    
    for(int i=0; i<N-1; i++){
        int p,q,r; cin >> p >> q >> r;
        dist[p].push_back({r,q});
        dist[q].push_back({r,p});
    }

    for(int i=0; i<Q; i++){
        int k,v; cin >> k >> v;

        int cnt=0;
        fill(vis, vis+N+1, 0);
        queue<int> q;
        q.push(v);
        vis[v]=1;

        while(!q.empty()){
            auto x = q.front(); q.pop();

            for(int i=0; i<dist[x].size(); i++){
                auto nx = dist[x][i];
                if(nx.first >= k && !vis[nx.second]){
                    vis[nx.second]=1;
                    q.push(nx.second);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
}