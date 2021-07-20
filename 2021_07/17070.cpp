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

int N, cnt=0; 
int arr[16][16];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};

void dfs(int x, int y, int before){//0 가로 ,1세로, 2대각선
    if( x==N-1 && y==N-1 ){
        cnt++;
        return;
    }

    for(int i=0; i<3; i++){ 
        if( (i==0 && before==1) || (i==1 && before==0)) 
            continue;   //가로로 옮길건데 전이 세로였거나 그반대였을경우 컷

        int nx = x+dx[i];
        int ny = y+dy[i];

        if( nx >= N || ny >= N || arr[nx][ny] == 1 )
            continue;   //마지노선과 공통으로 벽때문에 안되는경우

        if( i==2 && (arr[nx-1][ny]==1 || arr[nx][ny-1]==1))
            continue; // 대각선일때 벽있는경우

        dfs(nx, ny, i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    dfs(0,1,0);
    cout << cnt;
}