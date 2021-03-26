#include <iostream>
#include <queue>
#include <algorithm>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M, V, t1, t2, temp;
vi graph[1001];
bool visited[1001];

void dfs(int x){

    visited[x] = true;
    cout << x << " ";

    for(int i=0; i<graph[x].size(); i++)
        if( visited[graph[x][i]] == false ) 
            dfs(graph[x][i]);
    
}

void bfs(int x){

    queue<int> q;
    
    q.push(x);
    visited[x] = true;

    while(!q.empty()){
        x = q.front();
        q.pop();
        cout << x << " ";

        for( int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            
            if( visited[y] == false ){
                visited[y] = true;
                q.push(y);
            }

        }

    }    

}

void debug(){
    
    // graph에 값 제대로 들어가는지 디버깅
    for(int i=1; i<=N; i++){
        for(int j=0; j< graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> V;
    
    while(M--){
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    for(int i=1; i<=N; i++)
        sort(graph[i].begin(), graph[i].end());

    //debug();

    dfs(V);

    std::fill(begin(visited), std::end(visited), false);
    cout << endl;
    
    bfs(V);
}