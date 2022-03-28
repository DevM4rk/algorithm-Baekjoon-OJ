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
    
vector<bool> v(21);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m; cin >> m;

    while(m--){
        string s; cin >> s;
        int x;
        if(s == "add"){
            cin >> x;
            v[x] = true;
        }
        else if(s == "check"){
            cin >> x;
            if(v[x]) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "remove"){
            cin >> x;
            v[x] = false;
        }
        else if(s == "toggle"){
            cin >> x;
            if(v[x]) v[x] = false;
            else v[x] = true;
        }
        else if(s == "all"){
            for(int i=1; i<=20; i++) v[i] = true;
        }
        else if(s == "empty"){
            for(int i=1; i<=20; i++) v[i] = false;
        }
    }   
}
//10:44 ~ 