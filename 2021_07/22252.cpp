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

ll ans=0;
unordered_map<string, priority_queue<int>> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int Q; cin >> Q;
    while(Q--){
        int T; string str;
        cin >> T >> str;

        if(T==1){
            int k; cin >> k;

            while(k--){
                int t; cin >> t;

                m[str].push(t);
            }
        }
        else{ // T==2
            int b; cin >> b;

            while(b--){
                if(m[str].empty()) break;

                ans += m[str].top();
                m[str].pop();
            }
        }

    }
    cout << ans;
}