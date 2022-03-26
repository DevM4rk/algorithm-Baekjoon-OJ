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
int indeg[1001];
vi v[1001];
vi ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int t; cin >> t;
        int a,b; cin >> a;
        while(t--){
            if(t==0)break;
            cin >> b;
            v[a].push_back(b);
            indeg[b]++;
            a = b;
        }
    }

    queue<int> q;
    for(int i=1; i<=n; i++)
        if(indeg[i]==0) q.push(i);

    while(!q.empty()){
        int x = q.front(); q.pop();
        ans.push_back(x);
        
        for(int i=0; i<v[x].size(); i++){
            int nx = v[x][i];
            indeg[nx]--;
            if(indeg[nx]==0) q.push(nx);
        }
    }

    if(ans.size() != n){
        cout << 0;
    }
    else{
        for(auto a : ans) cout << a << endl; 
    }


}
//12:48 ~ 1:00