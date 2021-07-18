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

int N, MAX;
string s;

int cal(int a, int b, char op){

    switch (op){
    case '+': 
        a += b;
        break;

    case '-': 
        a -= b;
        break;

    case '*': 
        a *= b;
        break;
    }
    return a;
}

void dfs(int idx, int sum){
    
    if(idx >= N){
        MAX = max(MAX, sum);
        return;
    }
    
    char op = (idx == 0) ? '+' : s[idx-1];

    // 계산이 가능한지 체크.
    if(idx+2 < N){
        // 묶는다.
        int temp = cal(s[idx]-'0', s[idx+2]-'0', s[idx+1]);
        dfs(idx+4, cal(sum, temp, op));
    }

    // 안묶는다.
    dfs(idx+2, cal(sum, s[idx]-'0', op));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> s;

    MAX = INT_MIN; // 필수
    dfs(0,0);
    cout << MAX;
}
/*
3+8*7-9*2
(3+8)*7-9*2
(3+8)*(7-9)*2
(3+8)*7-(9*2)
3+(8*7)-9*2
3+(8*7)-(9*2)
3+8*(7-9)*2
3+8*7-(9*2)    // 8
*/