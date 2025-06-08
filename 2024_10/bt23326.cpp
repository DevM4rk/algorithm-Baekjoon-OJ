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

    int n,q; cin >> n >> q;
    vector<int> v(n+1);
    set<int> s;
    for(int i=1; i<=n; i++){
        cin >> v[i];
        if(v[i]) s.insert(i);
    }
    int x=1;
    while(q--){
        int num; cin >> num;
        if(num==1){
            cin >> num;
            v[num]=0;
            s.erase(num);

        }
        else if(num==2){
            cin >> num;
            x += num%n;
            x %= n;
            if(x==0) x=n;
        }
        else{
            if(s.empty()){
                cout << -1 << endl;
                continue;
            }

            int ans;
            auto a = s.lower_bound(x);
                // cout << *a  << " " << x << endl;

            if(a== s.end()){
                a = s.lower_bound(1);
                ans= n-x + *a;
            }
            else{
                ans = *a-x;
            }

            cout << ans << endl;
        }
    }
}