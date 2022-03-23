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

int indgree[32001];
vector<vi> v(32001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    for(int i=0; i<m; ++i){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        indgree[b]++;
    }

    priority_queue<int, vi, greater<int>> pq;
    for(int i=1; i<=n; ++i){
        if(indgree[i]) continue;
        pq.push(i);
    }

    while(!pq.empty()){
        int x = pq.top(); pq.pop();
        cout << x << " ";

        for(int i=0; i<v[x].size(); ++i){
            int nx = v[x][i];
            indgree[nx]--;
            if(indgree[nx]==0){
                pq.push(nx);
            }
        }
    }
}
//7:00 ~ :10