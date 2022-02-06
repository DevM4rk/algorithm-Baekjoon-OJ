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
ll s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;

    ll sum=0;
    for(int i=1; i<=s; i++){
        sum+=i;
        n++;
        //cout << n << " " << sum << endl;
        if(s < sum) break;
    }
    if(s==1) n=2;
    cout << n-1;

}
/*
1 2 3 4 5 6 7 8 9
1 3 6 10
*/