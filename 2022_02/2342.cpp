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

int dp[100001][5][5];
vi v;

int move(int from, int to){
    if(from==0) return 2;               // 초기값일 경우
    else if(from-to == 0) return 1;     // 같은 자리일 경우
    else if(abs(from-to) == 2) return 4;// 반대편일 경우
    else return 3;                      // 바로 옆일 경우
}

int dfs(int n, int l, int r){
    if(v.size() == n) return 0; //기저 사례 - 끝까지 확인한 경우
    int& ret = dp[n][l][r];     //보기좋으라고 한거임
    if(ret!=0) return ret;      //기저 사례 - 이미 계산이 끝난 경우
    
    //왼쪽, 오른쪽 두가지의 경우로 옮길때 최소값
    return ret = min( dfs(n+1, v[n], r) + move(l, v[n]),
                        dfs(n+1, l, v[n]) + move(r, v[n]) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1){
        int a; cin >> a;
        if(a==0) break;
        v.push_back(a);
    }

    cout << dfs(0,0,0) << endl;
}