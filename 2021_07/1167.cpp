#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int N, ans, farthestNode;
vpii vp[100001];
bool visited[100001];

void DFS(int n, int dist){
    visited[n] = true;
    
    // 간격이 가장 멀 때, 노드도 가장 멀리 있음 , 간격과 노드 모두 저장
    if(ans < dist){
        ans = dist;
        farthestNode = n;
    }

    for(int i=0; i < vp[n].size(); i++){
        if(visited[vp[n][i].first] == true) continue;
        DFS(vp[n][i].first, dist + vp[n][i].second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    for(int i=0; i < N; i++){

        int node;
        cin >> node;  
        
        while(1){
            int x,y;
            cin >> x;
            if( x == -1 ) break;
            cin >> y;

            vp[node].push_back({x,y});
        }
    }

    // 루트에서 가장 먼 정점을 찾은 후
    
    ans=0;
    DFS(1,0);

    // 그 정점에서 다시 또 먼 정점을 찾으면 그것이 지름

    memset(visited, false, sizeof(visited));
    ans=0;
    DFS(farthestNode,0);

    cout << ans;
}