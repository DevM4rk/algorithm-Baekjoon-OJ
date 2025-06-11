#include <bits/stdc++.h>

using namespace std;

int n,m, ans=1000; 
vector<int> v(111);
vector<int> vis(111);

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        v[a]=b;
    }
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        v[a]=b;
    }

    queue<pair<int,int>> q;
    q.push({1,0});
    vis[1]=0;

    while(!q.empty()){
        auto node = q.front(); q.pop();
        auto [x, cnt] = node;
        // cout << x << " " << cnt << " " << endl;
        if(x >= 100 ){
            ans = min(ans, cnt);
            break;
        }

        // if(vis[x]<=cnt && vis[x]!=0){
        //     continue;
        // }
        
        for(int i=1; i<=6; i++){
            int nx = x+i;
            if(v[nx]>0) nx = v[nx];
            if(vis[nx] > cnt+1 || vis[nx]==0){
                vis[nx] = cnt+1;
                q.push({nx,cnt+1});
            }
        }
        
    }
    

    cout << ans;
}