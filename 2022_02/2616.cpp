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

int n,m;
int sum[50001];
int dp[50001][4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        sum[i] = sum[i-1] + a;
    }
    cin >> m;

    // for(int i=1; i<=n; i++)
    //     cout << sum[i] << " ";
    // cout << endl;

    for(int i=1; i<=3; i++)
        for(int j=i*m; j<=n; j++)
            dp[j][i] = max(dp[j-1][i], dp[j-m][i-1] + sum[j]-sum[j-m]);

    // for(int i=1; i<=3; i++){
    //     for(int j=i*m; j<=n; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][3];
}