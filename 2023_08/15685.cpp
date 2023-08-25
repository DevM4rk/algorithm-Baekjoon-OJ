#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(101, vector<int>(101));

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int gen[11][1050];

void generation(){
    gen[1][0] = 1;
    for(int i=2; i<=10; i++){
        int ny = 1 << i-2;
        for(int a=0; a<ny; a++){
            gen[i][a] = gen[i-1][ny-1-a] + 1;
            if(gen[i][a] == 4) gen[i][a] = 0;
        }
        for(int a=ny; a<ny*2; a++){
            gen[i][a] = gen[i-1][a-ny];
        }
    }

    // for(int i=0; i<5; i++){
    //     for(int j=0; j<33; j++){
    //         cout << gen[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}


int main(){
    int n; cin >> n;

    generation();

    for(int i=0; i<n; i++){
        int x,y,d,g;    cin >> y >> x >> d >> g;
        
        v[x][y] = 1;
        x += dx[d];
        y += dy[d];
        v[x][y] = 1;

        for(int j=1; j<=g; j++){
            for(int k=0; k < 1<<j-1; k++){
                int a = gen[j][k] + d;
                if(a >= 4) a-=4;
                x += dx[a];
                y += dy[a];

                v[x][y] = 1;
            }    
        }
    }

    int ans=0;

    for(int i=0; i<100; i++){
        int x1 = i;
        int x2 = i+1;
        for(int j=0; j<100; j++){
            if(v[x1][j] && v[x2][j] && v[x1][j+1] && v[x2][j+1]){
                ans++;
            }
        }
    }

    cout << ans;
}
/*
1

2
3 2
3 0 3 2

0

1
2 1
2 3 2 1


3

0
1 0                             - 1
1 2 1 0                         - 2
1 2 3 2 1 2 1 0                 - 3
1 2 3 2 3 0 3 2 1 2 3 2 1 2 1 0 - 4

[0 1 2 1 2 3 2 1]
3을 뒤집어서 +1하면
4의 앞 8개가 나옴
이걸 반복
*/