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

int n;
int t[501];
int indeg[501];
vi v[501];
queue<int> q;
int ans[501];
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> t[i];
        while(1){
            int a; cin >> a;
            if(a==-1) break;
            v[a].push_back(i);
            indeg[i]++;
        }
    }

    for(int i=1; i<=n; i++){
        if(!indeg[i]){
            q.push(i);
            ans[i] = t[i];
        }
    }
    
    while(!q.empty()){
        int V = q.front(); q.pop();

        for(auto nV : v[V]){
            ans[nV] = max(ans[nV], ans[V] + t[nV]);

            indeg[nV]--;
            if(indeg[nV]==0) q.push(nV);
        }
    }

    for(int i=1; i<=n; i++) cout << ans[i] << "\n";
}