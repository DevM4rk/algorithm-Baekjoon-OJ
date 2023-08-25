#include <bits/stdc++.h>

using namespace std;

int n=100,m,ans=INT_MAX;
vector<vector<int>> v(n, vector<int>(n));
vector<pair<int,int>> ck;
vector<int> vis(13);

void cal(){
    int sum=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(v[i][j]==1){
                int x = INT_MAX;
                for(int k=0; k<ck.size(); k++){
                    if(vis[k]) continue;
                    x = min(x, abs(i-ck[k].first) + abs(j-ck[k].second));
                    //cout << i << " " << j << " " << x << endl;
                }
                sum += x;
            }
        }
    }
    // int x=0;
    // x = ans;
    ans = min(ans,sum);
    // if( x != ans )
    //     for(int i=0; i<13; i++)
    //         cout << vis[i] << " " ;
    // cout << endl;
        
}

void dfs(int x, int cnt){
    if(cnt == ck.size()-m){
        cal();
        return;
    }

    for(int i=x; i<ck.size(); i++){
        vis[i] = 1;
        dfs(i+1, cnt+1);
        vis[i] = 0;
    }
}

int main(){
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
            if(v[i][j]==2) ck.push_back({i,j});
        }
    }

    dfs(0,0);

    cout<< ans;

}