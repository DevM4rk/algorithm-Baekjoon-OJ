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

int N,L,R;
int arr[51][51];
bool vis[51][51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void bfs(int a, int b){

    vis[a][b] = true;
    queue<pii> q, save;
    q.push({a,b});
    save.push({a,b});
    int cnt=1, sum = arr[a][b];

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx >= N || ny >= N) continue;
            if(vis[nx][ny]) continue;

            int temp = abs(arr[nx][ny] - arr[x][y]);
            if(L <= temp && temp <= R){
                vis[nx][ny] = true;
                q.push({nx,ny});
                save.push({nx,ny});
                cnt++;
                sum+=arr[nx][ny];
            }
        }    
    }

    int people = sum / cnt; // 소수점 버려지는지 확인해야함

    while(!save.empty()){
        auto cur = save.front(); save.pop();
        int x = cur.first;
        int y = cur.second;

        arr[x][y] = people;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> L >> R;

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    int ans=0;
    while(true){

        int cnt=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(vis[i][j]) continue;
                bfs(i,j);
                cnt++;
            }
        }
        if(cnt == N*N) break;        

        //vis초기화
        for(auto v : vis) fill(v, v+N, false);

        ans++;
    }

    cout << ans;
}
//11:00 ~ 11:40