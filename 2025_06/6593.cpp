#include <bits/stdc++.h>

using namespace std;

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

vector<vector<vector<char>>> bd(30, vector<vector<char>>(30, vector<char>(30)));
vector<vector<vector<char>>> vis(30, vector<vector<char>>(30, vector<char>(30)));
int zz,xx,yy;
int main(){
    
    while(1){
        cin >> zz >> xx >> yy;
        if(zz==0&&yy==0&&xx==0) break;
        int ans=-1;
        tuple<int,int,int> st,end;

        for(int i=0; i<zz; i++){
            for(int j=0; j<xx; j++){
                for(int k=0; k<yy; k++){
                    cin >> bd[i][j][k];
                    if (bd[i][j][k] == 'S') st = {i,j,k};
                    if (bd[i][j][k] == 'E') end = {i,j,k};
                }
            }
        }

        queue<pair<tuple<int,int,int>,int>> q;
        auto [stz,stx,sty] = st;
        q.push({st,0});
        vis[stz][stx][sty] = 1;

        while(!q.empty()){
            auto node = q.front(); q.pop();
            auto [tp,cnt] = node;
            auto [z,x,y] = tp;

            // cout << z << " " << x<< " "  << y<< " " <<cnt << endl;

            if(bd[z][x][y] == 'E'){
                ans = cnt;
                break;
            } 

            for(int i=0; i<6; i++){
                int nx=x,ny=y,nz=z;
                if(i<4){
                    nx = x + dx[i];
                    ny = y + dy[i];
                }
                if(i==4){
                    nz++;
                }
                if(i==5){
                    nz--;
                }

                if(nx<0|| ny<0 || nz<0 || nx>=xx || ny>=yy || nz>=zz) continue;

                if(vis[nz][nx][ny])continue;
                if(bd[nz][nx][ny] == '#') continue;
                vis[nz][nx][ny] = 1;

                q.push({{nz,nx,ny},cnt+1});

            }
        }
        
        if(ans==-1){
            cout << "Trapped!" << "\n";
        }
        else{
            cout << "Escaped in " << ans << " minute(s)." << "\n";
        }

        bd = vector<vector<vector<char>>> (30, vector<vector<char>>(30, vector<char>(30)));
        vis = vector<vector<vector<char>>> (30, vector<vector<char>>(30, vector<char>(30)));
    }
}