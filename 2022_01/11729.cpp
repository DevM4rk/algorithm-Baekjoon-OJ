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

void top(int a, int b, int k, int c){
    if(k==1){
        cout << a << " " << b << "\n";
        return;
    }
    
    top(a, c, k-1, b);
    cout << a << " " << b << "\n";
    top(c, b, k-1, a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    cout << (1<<n) - 1 << "\n";
    top(1, 3, n, 2);
}