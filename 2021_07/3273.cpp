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

int n,x,ans=0;
int a[100000];

void solve(){
    int s = 0;
    int e = n-1;
    
    while(s < e){
        if(a[s] + a[e] == x){
            ans++;
            s++;
        }
        else if(a[s] + a[e] > x){
            e--;
        }
        else{
            s++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> x;

    sort(a, a+n);
    
    solve();

    cout << ans;
}
//1 2 3 5 7 9 10 11 12   -> 13