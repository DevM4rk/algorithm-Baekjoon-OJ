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
int a[301], d[301][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    d[1][0] = a[1];
    d[1][1] = 0;
    d[2][0] = a[1]+a[2];
    d[2][1] = a[2];

    for(int i=3; i<=n; i++){
        d[i][0] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][0], d[i-2][1]) + a[i]; 
    }

    cout << max(d[n][0], d[n][1]);
}
/*
d[i][j] = 전에 j계단을 밟고 i까지 왔을 때 점수 합의 최대값
0 - 첫계단으로 오른 경우
1 - 두계단으로 오른 경우
d[i][0] = d[i-1][1] + a[i]; // 무조건 두계단 밟고왔어야함, 첫계단이면 연속3개밟힘
d[i][1] = max(d[i-2][0], d[i-2][1]) + a[i]; 전에 두 계단으로 오른경우 i-2가 첫계단이든 두계단을 밟고왔든 상관x

max(d[n][0] , d[n][1]);
*/