#include <bits/stdc++.h>

using namespace std;

int dp[1500000];

int main(){

    int n; cin >> n;

    for(int i=1; i<=n; i++){
        int a,b; cin >> a >> b;

        dp[i] = max(dp[i], dp[i-1]);
        if(i + a > n+1) continue;

        dp[i+a] = max(dp[i+a], dp[i] + b);

    }

    // int cnt=0;
    // for(auto a : dp){
    //     cout << cnt << " " <<a << endl;
    //     cnt++;
    // }

    cout << *max_element(dp, dp+n+2);
}
/*
dp[i] = x;
i일 일때 최대수익

1  2  3  4  5  6  7
         10 20    20
         10
         
감도안잡히는데 이거 맞나 dp 개어렵다ㅂㅈㄷ래ㅔㅏㅈ데ㅐ라
*/