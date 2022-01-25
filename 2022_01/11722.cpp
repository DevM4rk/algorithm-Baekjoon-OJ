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
int d[1001];
int a[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    fill(d, d+n, 1);

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            if(a[j] > a[i]) d[i] = max(d[i], d[j]+1);
    
    cout << *max_element(d, d+n);
}
