#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> v(4, vector<char>(8));
vector<int> d(4,2), vis(4); //d가 가르키는것은 3시

void cal(int x, int dir){
    vis[x] = true;
    // cout << x << " " << dir << endl;

    //     for(int i=0; i<4; i++) cout << d[i] << " " ;
    //     cout << endl;
        

    int cp_d = d[x];

    if(dir == 1) d[x]--;
    else d[x]++;

    if(d[x] < 0) d[x]= 7;
    else if(d[x] >= 8) d[x]=0;


    int nx = x-1;
    int rd = cp_d+4;
    if( rd >= 8 ) rd = cp_d-4;

    if( nx >= 0 && !vis[nx]){    //nx가 -1일때 에러조심
        if(v[x][rd] != v[nx][d[nx]]){
            if(dir==1) cal(nx, -1);
            else cal(nx, 1);
        }
    }


    nx = x+1;
    rd = d[nx]+4;
    if( rd >= 8 ) rd = d[nx]-4;

    if( nx < 4 && !vis[nx]){
        if(v[x][cp_d] != v[nx][rd]){
            if(dir==1) cal(nx, -1);
            else cal(nx, 1);
        }
    }
}

int main(){

    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            cin >> v[i][j];
        }
    }

    int k; cin >> k;

    for(int i=0; i<k; i++){
        int num, dir; cin >> num >> dir;
        num--;

        cal(num,dir);

        fill(vis.begin(), vis.end(), 0);       
    }
    
    int ans=0;
    for(int i=0; i<4; i++){
        int x = d[i]-2;
        if(d[i]-2 < 0) x = d[i]+6;
        //cout << x << " ";
        if(v[i][x] == '1') ans += 1 << i;
    }

    cout << ans;
}

/*
10101111
  3   9
인덱스 2에서 4더하면 6반대편

극이 다르면 반대로 돌리고 같으면 멈춰있음
1시계방향
-1 반시계 방향

지나갔다는 vis 체크
번호, 방향 넘김
번호에 -1, +1을 하면서 0,4를 넘지않게끔
s/n극 체크 후 반대면 d 조정하고 또 함수로 넘겨서 반복

끝나면 vis 초기화
*/