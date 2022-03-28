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

map<string, int> word;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;

    vector<string> ans;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        if(s.size() < m) continue;

        word[s]++;
    }

    for(auto &[k,v] : word) ans.push_back(k);

    sort(all(ans), [&](string &a, string &b){
        if(word[a] == word[b]){
            if(a.size() == b.size()){
                return a < b;
            }
            return a.size() > b.size();
        }
        return word[a] > word[b];
    });

    for(auto a : ans) cout << a << "\n";

}
//9:34 ~ 10:08