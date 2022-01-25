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
vpii v;
int d[101];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n;

    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    sort(all(v));

    fill(d,d+n,1);

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
            if(v[j].second < v[i].second)
                d[i] = max(d[i], d[j]+1);

    cout << n - *max_element(d, d+n);
}