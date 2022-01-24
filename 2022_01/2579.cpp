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
int a[301], d[301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    d[1] = a[1];
    d[2] = a[1] + a[2];
    d[3] = a[3] + max(d[1], a[2]);  //요기도 조심

    for(int i=4; i<=n; i++)
        d[i] = a[i] + max(d[i-3]+a[i-1], d[i-2]);

    cout << d[n];
}
/*
d 테이블의 정의 : 계단 오를 때 되는 것만 고려해서 더한 최대값
d[n] 계산 시 고려할 점
1. n-1 계단을 더하려고 할 때, n-2를 거쳐왔으면안됨 a[n-1] + d[n-3]
2. n-2 계단을 더하려고 할 때, 그전에 뭘했든 상관없음 d[n-2]
*/