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

int n, m;
int a[100001];
int ans = INT_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);

    int e=1;
    for(int i=0; i<n; i++){
        while(a[e]-a[i] < m){
            if(e < n-1) e++;
            else break;
        }
        if(a[e]-a[i] >= m) ans = min(ans, a[e]-a[i]);
    }// 1 2 3 4 5

    cout << ans;
}
//e-s = m
//e = s+m