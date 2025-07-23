#include <bits/stdc++.h>

using namespace std;

long long dp[91];

int main(){

    long long a; cin >> a;

    dp[1]=1;//1
    dp[2]=1;//10        
    // dp[3]=2;//100 101
    // dp[4]=3;//1000 1001 1010 
    // dp[5]=5;//10000 10001 10010 10100 10101

    for(int i=3; i<=90; i++) dp[i] = dp[i-1] + dp[i-2];

    cout << dp[a];
}