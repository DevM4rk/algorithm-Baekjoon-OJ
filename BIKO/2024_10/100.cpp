#include <bits/stdc++.h>

using namespace std;

int dx[] ={0,0,1,-1, -1,-1,1,1}; // 0~3���� 4~7�밢
int dy[] ={-1,1,0,0, -1,1,-1,1};

int n,m,ans;
int board[50][50];

int dfs(int x, int y, int dir){
    int sum = board[x][y];

    if(dir == 1){
        for(int i=0; i<4; i++){
            int nx=x;
            int ny=y;
            for(int j=0; j<m; j++){
                nx +=dx[i];
                ny +=dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                sum += board[nx][ny];
            }
        }
    }
    else{
        for(int i=4; i<8; i++){
            int nx=x;
            int ny=y;
            for(int j=0; j<m; j++){
                nx +=dx[i];
                ny +=dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                sum += board[nx][ny];
            }
        }
    }

    return sum;
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){            
            ans = max(ans, dfs(i,j,1)); //����

            ans = max(ans, dfs(i,j,2)); //�밢
        }
    }

    cout << ans;
}
/*
����
    
    �߾� ���ϱ�
    �׳� ��������
    for(���� ) if 1�̸� 0~3 2�� 4~7
        for(j=1���� m) 
            if(�����۾ȳ�����)
    

*/