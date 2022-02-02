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

    string s,boom; cin >> s >> boom;
    string ans="";

    for(auto c : s){
        ans+=c;
        if(ans.back() == boom.back() && ans.size() >= boom.size()){
            int st = ans.size()-boom.size();
            string temp="";
            for(int i=st; i<ans.size(); i++)
                temp+=ans[i];

            if(temp == boom) ans.erase(st);
        }
    }
    
    if(ans.empty()) cout << "FRULA";
    else cout << ans;
}