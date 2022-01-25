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

int n,m,r;
int t[102];
int a,b,l;
int ans;
int d[102][102];

void floyd(){
    for(int i=1; i<=n; i++)            //i가 경유지
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++)
                if(d[k][i] != INT_MAX && d[i][j] != INT_MAX)
                    d[k][j] = min(d[k][j], d[k][i] + d[i][j]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;
    
    for(int i=1; i<=n; i++)
        cin >> t[i];
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            d[i][j] = INT_MAX;
    
    for(int i=1; i<=n; i++)
        d[i][i] = 0;
    
    for(int i=0; i<r; i++){
        cin >> a >> b >> l;
        d[a][b] = l;
        d[b][a] = l;
    }

    floyd();
    
    for(int i=1; i<=n; i++){
        int temp=0;

        for(int j=1; j<=n; j++)
            if(d[i][j] <= m) temp += t[j];

        ans = max(ans, temp);
    }
    
    cout << ans;

}
//11:20 ~ 38