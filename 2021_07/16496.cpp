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

int N;
vector<string> v;
string ans;

bool cmp(const string& a, const string& b){
    return a+b > b+a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    for(int i=0; i<N; i++){
        string s; 
        cin >> s;
        v.push_back(s);
    }

    sort(all(v), cmp);

    for(auto &a : v) ans += a;

    if(ans[0] == '0') ans = "0";
    cout << ans;
}