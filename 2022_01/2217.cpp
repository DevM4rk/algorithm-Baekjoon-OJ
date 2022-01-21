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

int n,ans;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n, greater<>());

    for(int i=0; i<n; i++){
        int w = arr[i] * (i+1);
        ans = max(ans, w);
    }

    cout << ans;
}