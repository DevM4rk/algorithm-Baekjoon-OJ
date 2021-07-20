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

int N,M,D,ans=0;
int arr[16][16];
int dx[3] = {0,-1,0};   // 좌 상 우
int dy[3] = {-1,0,1};  // 0,-1 / -1,0 / 0,1

void solve(int a1, int a2, int a3){
    int map[16][16];
    int cnt=0;
    bool visited[16][16];

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map[i][j] = arr[i][j];
            visited[i][j] = false;
        }
    }


    for(int pos=N; pos>0; pos--){ // 성의위치부터 위로, 궁수의 위치는 [pos][a]

        queue<pii> q;
        q.push({pos-1,a1});
        //visit

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            for(int d=0; d<D; d++){
                for(int i=0; i<3; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    // nx ny가 n m 을 넘어가면 안되며

                    // 0을 찾을경우 q 에 담고
                    // 1을 찾을경우 
                    // visited 을 계속 하면서 가야댐 3의경우 왼오 가 되면 겹침
                    
                }
            }
        }




    }

    ans = max(ans, cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> D;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> arr[i][j];

    for(int i=0; i<M; i++)
        for(int j=i+1; j<M; j++)
            for(int k=j+1; k<M; k++)
                solve(i,j,k);
        
    cout << ans;
}