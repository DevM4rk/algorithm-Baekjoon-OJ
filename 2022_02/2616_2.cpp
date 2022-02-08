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
int arr[50001];
int sum[50001];
int dp[50001][4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    cin >> m;

    int plus=0;
    for(int i=1; i<=m; i++)
        plus += arr[i];

    int s=1,e=m+1;
    for(int i=m; i<=n; i++){
        sum[i] = plus;
        plus += arr[e] - arr[s];
        e++; s++;
    }

    // for(int i=1; i<=n; i++)
    //     cout << sum[i] << " ";
    // cout << endl;

    for(int i=1; i<=3; i++)
        for(int j=i*m; j<=n; j++)
            dp[j][i] = max(dp[j-1][i], dp[j-m][i-1] + sum[j]);

    // for(int i=1; i<=3; i++){
    //     for(int j=i*m; j<=n; j++){
    //         cout << dp[j][i] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][3];
}
// 처음 생각한 dp
//  75 90 60 40 75 105
//1 75 90 90 90 90 105
//2 135 135 165 195
//3 