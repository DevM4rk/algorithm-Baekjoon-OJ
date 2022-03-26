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

    string s; cin >> s;
    int ans=2e9, acnt=0;

    for(auto c : s){
        if (c == 'a') acnt++;
    }

    for(int i=0; i<s.size(); i++){
        int cnt=0;

        for(int j=i; j<i+acnt; j++){
            if(s[j%s.size()] == 'b') cnt++;
        }

        ans = min(ans, cnt);
    }
    cout << ans;
}