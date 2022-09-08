#include <bits/stdc++.h>

using namespace std;

int MOD = 20170805;
int dp[501][501][2]; //0은 오른쪽, 1은 아래

int solution(int n, int m, vector<vector<int>> city_map) {
    int answer = 0;
    memset(dp,?0,?sizeof(dp));

    dp[1][1][0] = dp[1][1][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(city_map[i-1][j-1] == 0){        //자유
                dp[i][j][0] += (dp[i-1][j][1] + dp[i][j-1][0]) % MOD;
                dp[i][j][1] += (dp[i-1][j][1] + dp[i][j-1][0]) % MOD;
            }
            else if(city_map[i-1][j-1] == 1){   //못 지나감
                dp[i][j][0] = dp[i][j][1] = 0;
            }
            else if(city_map[i-1][j-1] == 2){   //한 방향
                dp[i][j][0] = dp[i][j-1][0] % MOD;
                dp[i][j][1] = dp[i-1][j][1] % MOD;
            }
        }
    }
    
    
    return dp[n][m][0] % MOD;
}