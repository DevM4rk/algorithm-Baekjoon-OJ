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

    set<int> s = {2,5};

    int m; cin >> m;
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        s.insert(a);
        s.insert(b);
        s.insert(c);

    while(t--){
        char c; cin >> c;
        if(c == 'I'){
            int k,s; cin >> k >> s;
            
            for(int i=0; i<v[0].size(); i++){
                if(v[0][i].first == k){
                    v[0].erase(v[0].begin()+i);
                    break;
                }
            }
            v[0].push_back({k,s});

            
        }
        else{ // F
            int k; cin >> k;
            //cout 
        }
    }
}