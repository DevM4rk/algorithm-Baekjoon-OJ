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
ll ans;
int a[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);

    int t;  
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            t = -1 * (a[i]+a[j]);     // a+b+c=0 ,  c = -(a+b)
            ans += upper_bound(a+j+1, a+n, t) - lower_bound(a+j+1, a+n, t);
        }
    }

    cout << ans;
}