#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int dp[1000001];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    dp[1] = 0;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        if(i%2 ==0) dp[i] = min(dp[i], dp[i/2]+1);
        if(i%3 ==0) dp[i] = min(dp[i], dp[i/3]+1);
    }
    cout << dp[n];
}