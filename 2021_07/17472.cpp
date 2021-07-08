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

int N,M,num,ans;
int arr[10][10];
bool visited[10][10];
vpii v[6];
vector<pair<int, pii>> dist;
int p[6];

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
    v[num].push_back({a,b});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int dx = x + ex[i];
            int dy = y + ey[i];
            
            if( dx < 0 || dy < 0 || dx >= N || dy >= M ) continue;

            if( arr[dx][dy] && !visited[dx][dy] ){
                q.push({dx,dy});
                visited[dx][dy] = true;
                v[num].push_back({dx,dy});
            }
        }
    }

    num++;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];
   
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(arr[i][j] && !visited[i][j])
                BFS(i,j);

    
    //cout << num;

    for(int i=0; i<num; i++){   // i번째섬에서
        for(int k=i+1; k<num; k++){     //k번째섬으로
            int d=10;
          
            for(int j=0; j<v[i].size(); j++){
                int x1 = v[i][j].first;
                int y1 = v[i][j].second;
               // cout << x1 << ","<< y1 << " ";

                for(int l=0; l<v[k].size(); l++){
                    int x2 = v[k][l].first;
                    int y2 = v[k][l].second;
                    //cout << x2 << ","<< y2 << endl;
                    if( x1 == x2 ){
                        int temp = abs(y1-y2)-1;  //가중치
                        if (temp < 2) d=0;
                        d = min(d,temp);
                    }

                    if( y1 == y2 ){
                        int temp = abs(x1-x2)-1;  //가중치
                        if (temp < 2) d=0;
                        d = min(d,temp);
                    }
                }
            }
        
                cout << d << " " << i << " " << k << endl;
            if( d!=10 && d!=0 ){
                dist.push_back({d,{i,k}});
            }
        }
    }

    sort(all(dist));

    for(int i=0; i<num; i++) p[i]= i;

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

    bool check = true;

    for(int i=1; i<num; i++)
        if(find(0) != find(i))
            check = false;
            
    if(check) cout << ans;
    else cout << -1;
}

/*
섬에 번호를 매김 DFS, BFS(섬이 몇개있는지 구분,)
섬의 모든 좌표도 같이 저장

섬에서 섬으로 가는 간선과 가중치를 계산 
같은 x축 , 같은 y축,없다면 0, 간격2이상이어야함 

정렬 후 크루스칼알고리즘사용
*/