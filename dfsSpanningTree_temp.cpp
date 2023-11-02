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

int T,n;
vi v[100001];
bool visited[100001];
bool finished[100001];
bool iscycle[100001];
int parent[100001];
int cnt;

void cycle(int node, int next){

    iscycle[node] = true;
    cnt++;

    if( node == next) return;

    cycle(parent[node], next);
}

void dfs(int node){
    visited[node] = true;

    for(int i=0; i<v[node].size(); i++){
        int next = v[node][i];
        if(!visited[next]){
            parent[next] = node;
            dfs(next);
        } 
        else if(!finished[next]){   //종료되지 않은 정점이라면 사이클
            cycle(node, next);
        }
    }

    finished[node] = true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--){
        cin >> n;

        cnt=0;
        for(int i=0; i<=n; i++){
            v[i].clear();
            parent[i] = i;
            visited[i] = false;
            finished[i] = false;
            iscycle[i] = false;
        }
        
        for(int i=1; i<=n; i++){
            int a;
            cin >> a;
            v[i].push_back(a);
        }

        for(int i=1; i<=n; i++){
            if(!visited[i])
                dfs(i);
        }

        cout << n - cnt << endl;
    }
}