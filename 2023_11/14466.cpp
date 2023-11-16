#include <bits/stdc++.h>

using namespace std;

int n,k,r,ans;
int d[101][101];
vector<pair<int,int>> v[101][101], cow;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    cin >> n >> k >> r;
    for(int i=0; i<r; i++){
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        v[x1][y1].push_back({x2,y2});
        v[x2][y2].push_back({x1,y1});
    }
    for(int i=0; i<k; i++){
        int x,y; cin >> x >> y;
        cow.push_back({x,y});
    }

    for(int i=k-1; i>=0; i--){
        auto [a,b] = cow[i];
        for(auto dist : d) fill(dist, dist+n+1, INT_MAX);
        d[a][b] = 0;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,a,b});

        while(!pq.empty()){
            auto [dist,x,y] = pq.top(); pq.pop();
            
            if(dist == 1) continue;

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
                int road=0;
                for(int j=0; j<v[x][y].size(); j++){
                    auto [x1,y1] = v[x][y][j];
                    if( x1 == nx && y1 == ny){
                       road++;
                       break;
                    }
                }

                if(d[nx][ny] > dist + road){
                    d[nx][ny] = dist + road;
                    pq.push({d[nx][ny], nx,ny});
                }
            }
        }

        for(auto [x,y] : cow){
            if(d[x][y] > 0) ans++;
        }

        cow.pop_back();
    }

    cout << ans;
}