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
int cost[10001];
vi v[10001];
bool visit[10001];
int dp[10001][2];

void dfs(int x){
    visit[x] = true;

    dp[x][0] = 0;
    dp[x][1] = cost[x];


    for(int i=0; i<v[x].size(); i++){
        int nx = v[x][i];
        if(visit[nx]) continue;

        dfs(nx);
        
        //현재 마을이 우수 마을이 아니라면 다음 마을은 우수 마을이거나 우수 마을이 아님
        dp[x][0] += max(dp[nx][0], dp[nx][1]);
        //현재 마을이 우수 마을이면 다음은 우수마을이 아님
        dp[x][1] += dp[nx][0];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> cost[i];
    
    for(int i=1; i<n; i++){
        int a,b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]);
}