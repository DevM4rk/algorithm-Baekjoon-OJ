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

int t,k;
string s;
int mn=10001,mx;
vi v[26];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> s >> k;

        for(int i=0; i<s.size(); i++){
            int a = s[i]-'a';
            v[a].push_back(i);
            if(v[a].size() >= k){
                int t = i - v[a][v[a].size() - k] + 1;
                mn = min(mn, t);
                mx = max(mx, t);
                //cout << t << " " << mn << " " << mx << endl;
            }
        }

        if(mn == 10001 || mx == 0) cout << -1 << "\n";
        else cout << mn << " " << mx << "\n";

        for(int i=0; i<26; i++)
            v[i].clear();
        mn = 10001; 
        mx = 0;
    }
}