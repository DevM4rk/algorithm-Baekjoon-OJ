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

int n; 
ll MAX = 9876543210;
vl v;
unordered_map<string,int> m;

void dfs(string x, int cnt){
    //cout << x << " " << cnt << endl;
    if(cnt==10){
        //cout << x << endl;
        if(x!=""){
            v.push_back(stoll(x));
            m[x]++;
        }
        return;
    }

    //넣는 경우, 안 넣는 경우
    for(int i=9-cnt; i>=0; i--){
        if(m.count(x+to_string(i))) continue;

        if(x.empty() || x.back()-'0' > i){
            dfs(x+to_string(i), cnt+1);
            dfs(x, cnt+1);
        }
    }
}
/* 숫자 작게 돌려보자
9876543210
987654321
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    dfs("",0);
    sort(all(v));

    //for(auto a : v) cout << a << " ";
    if(n >= v.size()) cout << -1;
    else cout << v[n];
}
// 9,876,543,210  longlong
/*
0 1 2 3 4 5 6 7 8 9 , 10개 !0번부터 세는거 주의
10 1개
20 21 2개
30 31 32 3개
40 41 42 43 4개
*/