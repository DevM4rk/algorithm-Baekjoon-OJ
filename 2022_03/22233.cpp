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

    int n,m; cin >> n >> m;
    unordered_set<string> memo;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        memo.insert(s);
    }

    for(int i=0; i<m; i++){
        vector<string> k;
        string s; cin >> s;
        
        int st=0, next=s.find(',');
        if(next == string::npos){
            k.push_back(s);
        }
        else{
            while(1){
                string temp = s.substr(st, next-st);
                k.push_back(temp);
                //cout << temp << endl;
                st = next+1;
                next = s.find(',', st);

                if(next == string::npos){
                    temp = s.substr(st);
                    k.push_back(temp);
                    break;
                }
            }
        }

        for(auto str : k){
            if(memo.count(str)) memo.erase(str);
        }

        cout << memo.size() << endl;
    }
}
//2:30 ~ 45