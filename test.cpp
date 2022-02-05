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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n = 1<<6;
    int c = 'a'-'a';
    int key = 1<<c;
    cout << n << " " << c << " " << key;
    int t = 1<<'b'-'a';
    key = key | t;
    cout << endl << t << " " <<  key << endl;

    int ans = key & (1<<3);
    cout << ans;
}