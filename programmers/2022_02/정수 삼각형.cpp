#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[500][500]={};

int solution(vector<vector<int>> t) {
    int answer = 0;
    int n = t.size();
    dp[0][0]=t[0][0];
    
    for(int i=1; i<n;i++){
        for(int j=0; j<t[i].size();j++){
            if(j==0)
                dp[i][j] = t[i][j] + dp[i-1][0];
            else if(j==i)
                dp[i][j] = t[i][j] + dp[i-1][j-1];
            else
                dp[i][j] = t[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    answer = *max_element(dp[n-1], dp[n-1] + n);

    return answer;
}