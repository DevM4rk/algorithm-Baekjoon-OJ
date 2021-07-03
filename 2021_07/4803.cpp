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

int n, m, T, Case=0, no, li;
vi v[501];
bool visited[501];

void DFS(int x){
    visited[x] = true;

    for(int i=0; i<v[x].size(); i++){
        if (visited[v[x][i]] == true) {
            li++;
            continue;
        }
        no++; li++;
        DFS(v[x][i]);
    }
    //if(no < node) no=node;
    //if(li < line) li=line;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true){
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        T=0;
        Case++;
        for(int i=1; i<=500; i++) v[i].clear();
        memset(visited, false, sizeof(visited));

        while(m--){
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        // dfs 반복해야됨 방문false일동안(1번케이스)
        for(int i=1; i<=n; i++){
            if(visited[i] == false){
                no=1; li=0;
                DFS(i);
                if((no-1)*2 == li) T++;
            }
        }

        cout << "Case " << Case << ": ";
		if (T > 1)
			cout << "A forest of " << T << " trees." << '\n';
		else if (T == 1)
			cout << "There is one tree." << '\n';
		else if (T == 0)
			cout << "No trees." << '\n';
    }
    
}

// 트리의 성질 정점이 n개 , 간선이 n-1개 이게 아니면 그래프로 간주
// 양방향 확인해야돼서 간선이 2배 ( (n-1)*2 )