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

int N, V=1, t1, t2, cnt=0;
vi graph[26];
bool visited[26];

void dfs(int x){
    visited[x] = true;

    for(int i=0; i<graph[x].size(); i++){
        if( visited[graph[x][i]] == false ){
            dfs(graph[x][i]);
            cnt++;
        }
    }
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
            cout << i << " i " << j << " j " << graph[i][j] << " ";
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    char arr[N][N];
    int arr_num[N][N];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            arr_num[i][j] = cnt++;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << arr_num[i][j];
        }
        cout << endl;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if( arr[i][j] == '1'){
                
                if( arr[i-1][j] == '1' ){
                    graph[arr_num[i-1][j]].push_back(arr_num[i][j]);
                    graph[arr_num[i][j]].push_back(arr_num[i-1][j]);
                }
                if( arr[i][j-1] == '1' ){
                    graph[arr_num[i][j-1]].push_back(arr_num[i][j]);
                    graph[arr_num[i][j]].push_back(arr_num[i][j-1]);
                }
                if( arr[i+1][j] == '1' ){
                    graph[arr_num[i+1][j]].push_back(arr_num[i][j]);
                    graph[arr_num[i][j]].push_back(arr_num[i+1][j]);
                }
                if( arr[i][j+1] == '1' ){
                    graph[arr_num[i][j+1]].push_back(arr_num[i][j]);
                    graph[arr_num[i][j]].push_back(arr_num[i][j+1]);
                }
            }
        }
    }

    //for(int i=1; i<=N; i++)
    //    sort(all(graph[i]));


    debug();

    //dfs(V);

    //cout << cnt;

    //std::fill(begin(visited), std::end(visited), false);
    //memset(vistied, false, sizeof(visited));
    //cout << endl;
    
    //bfs(V);
}