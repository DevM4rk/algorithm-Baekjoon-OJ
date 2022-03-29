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

string s[8];
bool vis[9][9][9];
int ans;

int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<8; i++)
        cin >> s[i];
    
    queue<tp> q;
    q.push({0,7,0});    //time ,x, y

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int t,x,y; tie(t,x,y) = cur;

        //cout << t << " " << x << " " << y << endl;
        //0,7 도달하면 끝, t가 8초 이상이면 끝?
        if(t==8){
            ans=1; break;
        }

        for(int i=0; i<9; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t+1;
            if(nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;

            if(vis[nt][nx][ny]) continue;
            if(nx-t >= 0) if(s[nx-t][ny] == '#') continue;
            if(nx-t-1 >= 0) if(s[nx-t-1][ny] == '#') continue;
            
            vis[nt][nx][ny] = true;
            q.push({nt,nx,ny});

        }
    }

    cout << ans;
}  