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

int n,m;
int indegree[32001];    //들어오는 간선 체크
vi v[32001];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    while(m--){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        indegree[b]++;
    }

    for(int i=1; i<=n; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    while(!q.empty()){
        int node = q.front(); q.pop();
        cout << node << " ";

        for(int i=0; i<v[node].size(); i++){
            int x = v[node][i];
            indegree[x]--;
            if(indegree[x] == 0) q.push(x);
        }
    }   
}