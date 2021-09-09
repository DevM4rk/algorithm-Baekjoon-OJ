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

map<string,double> m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string s;
    int cnt=0;

    while(getline(cin, s)){
        m[s]++;
        cnt++;
    }

    for(auto mm : m){
        cout << fixed;
        cout.precision(4);
        cout << mm.first << " "<< mm.second*100/cnt << endl;
    }
}