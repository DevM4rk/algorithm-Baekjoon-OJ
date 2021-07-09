#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define MAX 10

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

int N,M,num=1,ans;
int arr[10][10];
bool visited[10][10];
vector<pair<int, pii>> dist;
int p[7];

int ex[4] = {0,1,0,-1};
int ey[4] = {1,0,-1,0};

int find(int x){
    if(p[x] == x) return x;

    int parent = find(p[x]);
    p[x] = parent;
    return parent;
}

void BFS(int a, int b){
    queue<pii> q;
    q.push({a,b});
    visited[a][b] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        arr[x][y] = num;

        for(int i=0; i<4; i++){
            int dx = x + ex[i];
            int dy = y + ey[i];
            
            if( dx < 0 || dy < 0 || dx >= N || dy >= M ) continue;

            if( arr[dx][dy] && !visited[dx][dy] ){
                q.push({dx,dy});
                visited[dx][dy] = true;
            }
        }
    }

    num++;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
   
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(arr[i][j] && !visited[i][j])
                BFS(i,j);

    //cout << num;

    for(int i=0; i<N; i++){   // i번째섬에서
        for(int j=0; j<M; j++){     //j번째섬으로
            if(arr[i][j] != 0){
                for(int k=0; k<4; k++){
                    int x = i;
                    int y = j;
                    int d = 0;

                    while(true){
                        x += ex[k];
                        y += ey[k];
 
                        if( x < 0 || y < 0 || x >= N || y >= M || arr[i][j] == arr[x][y] ) break;

                        if(arr[x][y] != 0){
                            //cout << d << " " << i << " " << j << " "<< x << " " << y <<endl;
                            if(d > 1){
                                //cout << d << " " << arr[i][j] << " " << arr[x][y] << endl;
                                dist.push_back({d,{arr[i][j],arr[x][y]}});
                            }
                            break;
                        }
                        d++;
                    }
                }
            }
        }
    }

    sort(all(dist));

    for(int i=1; i<=num-1; i++) p[i]= i;

    for(int i=0; i<dist.size(); i++){
        int weight = dist[i].first;
        int a = dist[i].second.first;
        int b = dist[i].second.second; 

        a = find(a);
        b = find(b);

        if(a == b) continue;

        p[a] = b;

        ans += weight;

    }

    for(int i=2; i<=num-1; i++)
        if(find(1) != find(i))
            ans = -1;
    
    cout << ans;
}

/*
섬에 번호를 매김 DFS, BFS(섬이 몇개있는지 구분,)
섬의 모든 좌표도 같이 저장

섬에서 섬으로 가는 간선과 가중치를 계산 
같은 x축 , 같은 y축,없다면 0, 간격2이상이어야함 

정렬 후 크루스칼알고리즘사용
*/