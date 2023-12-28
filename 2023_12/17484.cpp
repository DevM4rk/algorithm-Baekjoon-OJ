#include <bits/stdc++.h>
#define IMAX 2147000000

using namespace std;

int dy[] = {-1,0,1};

vector<vector<vector<int>>> dp(1001, vector<vector<int>>(1002, vector<int>(4, IMAX)));

int main(){
    int n,m; cin >> n >> m;

    for(int j=0; j<=m+1; j++){
        for(int k=0; k<3; k++){
            dp[0][j][k]=0;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> dp[i][j][3];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<3; k++){ 

                if(k==0){
                    dp[i][j][k] = dp[i][j][3] + min(dp[i-1][j][(k+1)%3], dp[i-1][j-1][(k+2)%3]);
                }
                else if(k==1){
                    dp[i][j][k] = dp[i][j][3] + min(dp[i-1][j-1][(k+1)%3], dp[i-1][j+1][(k+2)%3]);
                }
                else{
                    dp[i][j][k] = dp[i][j][3] + min(dp[i-1][j+1][(k+1)%3], dp[i-1][j][(k+2)%3]);
                }
                // cout << i-1 << j-1 << k << " " << dp[i][j][k] << endl;
                // cout << dp[i-1][j-1][(k+1)%3] << " " << dp[i-1][j-1][(k+2)%3] << endl;
                // cout << dp[i-1][j][(k+1)%3] << " " << dp[i-1][j][(k+2)%3] << endl;
                // cout << dp[i-1][j+1][(k+1)%3] << " " << dp[i-1][j+1][(k+2)%3] << endl;
            }
        }
    }

    int ans = 1000;

    for(int j=1; j<=m; j++){
        for(int k=0; k<3; k++){  
            ans = min(ans, dp[n][j][k]);
        }
    }

    cout << ans;
}
/*
dp
[x][y][dir] = dir방향으로 도착한 x,y의 최솟값
*/