#include <bits/stdc++.h>

using namespace std;

int n,m,h,ans=INT_MAX;
vector<vector<int>> v(31, vector<int>(11));

void debug(){
    for(int i=1; i<=h; i++){
        for(int j=1; j<n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool play(int cnt){
    for(int i=1; i<=n; i++){
        int x=i;
    
        for(int j=1; j<=h; j++){
            if(v[j][x-1]==1) x--;
            else if(v[j][x]==1) x++;
        }
    
        if(x != i) return false;
    }
    
    ans = min(ans,cnt);
    return true;
}

void dfs(int x, int y, int cnt){
    play(cnt);
    if(cnt == 3) return;

    // cout << x << " " << y << " " << cnt << endl;
    // debug();

    for(int i=x; i<=h; i++){
        for(int j=1; j<n; j++){
            if(v[i][j]) continue;
            if(v[i][j-1]==1 || v[i][j+1]==1) continue;

            v[i][j] = 1;
            dfs(i,j,cnt+1);
            v[i][j] = 0;
        }
    }
}

int main(){

    cin >> n >> m >> h;
           
    for(int i=1; i<=h; i++){
        v[i][0] = 2;
        v[i][n] = 2;
    }

    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        v[a][b]=1;
    }

    dfs(1,1,0);

    // cout << ans << endl;
    if(ans > 3) ans = -1;
    cout << ans;
}
/*

*/