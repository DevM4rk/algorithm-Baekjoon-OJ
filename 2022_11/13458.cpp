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

    int n; cin >> n;
    vi v(n,0);
    
    for(int i=0; i<n; i++)
        cin >> v[i];

    int a,b; cin >> a >> b;

    ll ans=0;

    for(auto p : v){
        p-=a;
        ans++;

        if(p>0){
            ans+=p/b;
            if(p%b>0) ans++;
        }
    }

    cout << ans;

}