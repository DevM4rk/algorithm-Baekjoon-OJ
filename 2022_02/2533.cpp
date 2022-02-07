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
int dp[1000001][2]; // 1 본인이 얼리어답터인경우, 얼리어답터의 최소값
bool visit[1000001];
vi v[1000001];

void dfs(int x){
    visit[x]=true;
    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int x = q.front(); q.pop();

        dp[x][1] = 1;

        for(auto nx : v[x]){
            if(visit[nx]) continue;
            dfs(nx);
            dp[x][0] += dp[nx][1];  // 일반인일 경우 , 친구가 모두 얼리어답터여야함
            dp[x][1] += min(dp[nx][1], dp[nx][0]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
}
//1:15~30