#include <bits/stdc++.h>

using namespace std;

struct Node{
    int cnt;
    int x;
    int y;
    int dir;
};

int n;
int vis[101][101][4];   //0��,1��,2��,3�� �ð����
int dx[] = {-1, 0, 1, 0};   //���� ���缭 �ð��������
int dy[] = {0, 1, 0, -1};

int solution(vector<vector<int>> board) {
    n = board.size();
    
    queue<Node> q;
    
    q.push({0,0,0,1});
    q.push({0,0,1,3});
    vis[0][0][1]=1;
    vis[0][1][3]=1;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cnt = cur.cnt;
        int x1 = cur.x;
        int y1 = cur.y;
        int dir1 = cur.dir;
        
        int x2 = x1 + dx[dir1];
        int y2 = y1 + dy[dir1];
        int dir2 = (dir1+2)%4;
        
        if((x1 == n-1 && y1 == n-1) || (x2 == n-1 && y2 == n-1)){
            return cnt;
        }
        
        for(int i=0; i<4; i++){
            int nx1 = x1 + dx[i];
            int ny1 = y1 + dy[i];
            int nx2 = x2 + dx[i];
            int ny2 = y2 + dy[i];
            if(nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= n) continue;
            if(nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= n) continue;//ȸ��# ���⼭ ����Ȯ������
            if(board[nx1][ny1] || board[nx2][ny2]) continue;
            
            if(!vis[nx1][ny1][dir1]){
                vis[nx1][ny1][dir1]=1;
                q.push({cnt+1,nx1,ny1,dir1});
            }
            if(!vis[nx2][ny2][dir2]){
                vis[nx2][ny2][dir2]=1;
                q.push({cnt+1,nx2,ny2,dir2});
            }
            
            //�� �̵����� ������ ȸ����
            if(dir1%2 != i%2){ // ȸ������ �����̸�
                if(!vis[x1][y1][i]){
                    vis[x1][y1][i]=1;
                    q.push({cnt+1,x1,y1,i});
                }
            }
        }
    }
    
    return 0;
}
//ȸ���� �� ���� �ִ��� �Ű澲�� �ʾƵ� �Ǵ� ������ ������ �������� ������ �����Ѵٴ� ���� ������ �� �������� ȸ���� �̷������ �Ѵٸ� ������ ���簢�� 4ĭ�� ������ ������ �ȴ�.