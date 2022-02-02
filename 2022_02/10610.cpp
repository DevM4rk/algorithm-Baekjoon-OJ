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

    string s; cin >> s;
    ll temp=0;
    bool check = false;
    for(auto c : s){
        if(c=='0') check = true;
        temp+= c-'0';
    }
    if(!check || temp%3 != 0) cout << -1;
    else{
        sort(all(s), greater<>());
        cout << s;
    }
}