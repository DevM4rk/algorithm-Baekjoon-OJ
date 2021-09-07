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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<string> v;
        for(int i=0; i<n; i++){
            string s; cin >> s;
            v.push_back(s);
        }
            
        sort(all(v));

        bool b = true;

        for(int i=0; i<n-1; i++){
            if( v[i].size() < v[i+1].size() ){
                if( v[i] == v[i+1].substr(0,v[i].size())){
                    b = false;
                    break;
                }
            }
        }

        if (b) cout << "YES"<<endl;
        else cout << "NO"<<endl;

    }
}