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

int n;
int v[101][101];
int vis[101][101];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> v[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            auto x = q.front(); q.pop();

            for(int j=1; j<=n; j++){
                if(v[x][j]==0) continue;
                if(vis[i][j]==1) continue;
                vis[i][j]=1;
                q.push(j);
            }

        }
    }


    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}