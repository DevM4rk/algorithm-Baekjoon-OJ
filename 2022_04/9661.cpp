#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n; cin >> n;

    n=n%5;
    if(n==1 || n==3 || n==4) cout << "SK";
    else cout << "CY";
}
/*
1 s
2 c
3 s
4 s
5 c

6 s
7 c
8 s
9 s
10 c

5·Î ²÷¾îÁü
*/