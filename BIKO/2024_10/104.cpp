#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,1,-1}; // D, A, S, W
int dy[] = {1,-1,0,0};

int n,m,sx,sy,ex,ey,ans_num;
string board[35], ans_str;
int vis[35][60];

void dfs(int x, int y, int dir, int cnt, string str){
    if(x==ex && y == ey){
        
        if(ans_num > cnt){
            ans_num = cnt;
            ans_str = str;
        }
        cout << " 2";

        return;
    }
cout << " 1" ;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(vis[nx][ny]) continue;
        if(board[nx][ny] == '#') continue;
        cout << nx << " " << ny << 
        switch(i){
            case 0:
                str.push_back('D'); break;
            case 1:
                str.push_back('A'); break;
            case 2:
                str.push_back('S'); break;
            case 3:
                str.push_back('W'); break;
        }
        vis[nx][ny] = true;
        if(dir != i && dir != 4) cnt++;

        dfs(nx,ny,i,cnt,str);
        
        str.pop_back();
        vis[nx][ny] = false;
        if(dir != i && dir != 4) cnt--;
    }
}

int main(){
    cin >> n >> m >> sx >> sy >> ex >> ey;
    sx--; sy--; ex--; ey--;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    vis[sx][sy] = true;
    dfs(sx,sy,4,0,"");

    cout << ans_num << endl << ans_str;   
}
/*
4 5
2 2 3 3
.....
.....
.....
.....
*/