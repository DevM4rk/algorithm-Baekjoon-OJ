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

int n,m,ans;
string s[20];
bool alpha[26];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y, int cnt){

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(alpha[s[nx][ny]-'A']) continue;
        
        alpha[s[nx][ny]-'A'] = true;
        dfs(nx,ny,cnt+1);
        alpha[s[nx][ny]-'A'] = false;
    }

    ans = max(ans, cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        cin >> s[i];
 
    alpha[s[0][0]-'A'] = true;
    dfs(0,0,1);
    
    cout << ans;
}