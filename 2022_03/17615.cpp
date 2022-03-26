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

    int n; string s; cin >> n >> s;
    int ans=2e9,rcnt=0,bcnt=0;

    for(auto c : s){
        if(c == 'R') rcnt++;
        else bcnt++;
    }

    //R left
    if(s[0]=='R'){
        int cnt=0;
        for(int i=0; i<s.size(); i++){  //연속된 R 찾기
            if(s[i] == 'B') break;
            cnt++;
        }
        ans = min(ans, rcnt-cnt);
    }
    else{
        ans = min(ans, rcnt);
    }

    //R right 
    if(s[n-1]=='R'){
        int cnt=0;
        for(int i=n-1; i>=0; i--){  //연속된 R 찾기
            if(s[i] == 'B') break;
            cnt++;
        }
        ans = min(ans, rcnt-cnt);
    }
    else{
        ans = min(ans, rcnt);
    }

    
    //B left
    if(s[0]=='B'){
        int cnt=0;
        for(int i=0; i<s.size(); i++){  //연속된 R 찾기
            if(s[i] == 'R') break;
            cnt++;
        }
        ans = min(ans, bcnt-cnt);
    }
    else{
        ans = min(ans, bcnt);
    }
    //B right
    if(s[n-1]=='B'){
        int cnt=0;
        for(int i=n-1; i>=0; i--){  //연속된 R 찾기
            if(s[i] == 'R') break;
            cnt++;
        }
        ans = min(ans, bcnt-cnt);
    }
    else{
        ans = min(ans, bcnt);
    }
    
    cout << ans;

}
//10:05 ~ 35