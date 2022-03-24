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

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int cnt=0;
    while(true){
        cnt++;
        int n; cin >> n;
        if(n==0) break;

        vector<vi> arr(n, vi(n, 0));
        vector<vi> vis(n, vi(n, 2e9));
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> arr[i][j];

        queue<pii> q;
        q.push({0,0});
        vis[0][0] = arr[0][0];

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int y = cur.second;

            for(int i=0; i<4; ++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis[nx][ny] > vis[x][y] + arr[nx][ny]){
                    vis[nx][ny] = vis[x][y] + arr[nx][ny];
                    q.push({nx,ny});
                }
            }
        }
        
        cout << "Problem " << cnt << ": " << vis[n-1][n-1] << endl;
    }
}
//9:50 ~ 10:01