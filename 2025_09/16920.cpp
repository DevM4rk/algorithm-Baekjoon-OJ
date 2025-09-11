#include <bits/stdc++.h>

using namespace std;

int n,m,p;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<char>> bd(1000, vector<char>(1000));
vector<int> s(10);
vector<int> ans(10);
set<int> q_empty;
queue<tuple<int,int,int>> q[10];

int main(){
    cin >> n >> m >> p;
    for(int i=1; i<=p; i++){
        cin >> s[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char a;
            cin >> a;
            bd[i][j] = a;
            if( isdigit(a)){
                q[a-'0'].push({i,j,0});
                ans[a-'0']++;
            }
        }
    }

    while(q_empty.size() != p){
        for(int i=1; i<=p; i++){
            for(int j=1; j<=s[i]; j++){ //j번 반복
                if(q[i].empty()){
                    q_empty.insert(i);
                    break;
                }

                auto [a,b,c] = q[i].front();
                int tcnt = c;

                while(!q[i].empty()){
                    auto [x,y,cnt] = q[i].front();
                    if(cnt != tcnt) break;
                    q[i].pop();

                    for(int k=0; k<4; k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
                        if(bd[nx][ny] != '.') continue;
                        bd[nx][ny] = i+'0';
                        ans[i]++;
                        q[i].push({nx,ny,cnt+1});
                    }
                }
            }
        }
    }

    for(int i=1; i<=p; i++){
        cout << ans[i] << " ";
    }

}

/*
7:10 ~ 
1억을 반복해야되는게 시간복잡도 걸림 
근데 더이상 못찾으면 그냥 끊으면 되네
4 6 
5 8 
1000 1002


5 16 2배?
1 1 1 1 1
# # # # 1
1 1 1 1 1
1 # # # #
1 1 1 1 1
*/