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

int n;
int dp[1000001];
int p[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    dp[1] = 0;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        p[i] = i-1;
        if(i%2 ==0){
            int t = dp[i];
            dp[i] = min(dp[i], dp[i/2]+1);
            if(t != dp[i]) p[i] = i/2;
        }
        if(i%3 ==0){
            int t = dp[i];
            dp[i] = min(dp[i], dp[i/3]+1);
            if(t != dp[i]) p[i] = i/3;
        } 
    }
    cout << dp[n] << "\n";
    while(n >= 1){
        cout << n << " ";
        n = p[n];
    }
}