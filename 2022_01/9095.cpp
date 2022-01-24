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

int t,n;
int d[11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    d[1] = 1; // 1
    d[2] = 2; // 1+1, 2
    d[3] = 4; // 1+1+1, 1+2, 2+1, 3
    for(int i=4; i<=10; i++)
        d[i] = d[i-3]+d[i-2]+d[i-1];

    cin >> t;
    while(t--){
        cin >> n;
        cout << d[n] << "\n";
    }
}