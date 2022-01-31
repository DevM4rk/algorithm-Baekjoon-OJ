#include <string>
#include <vector>

using namespace std;

int vis[200];
vector<vector<int>> c;

void dfs(int x){
    for(int i=0; i<c[x].size(); i++){
        if(!c[x][i] || vis[i]) continue;
        vis[i] = true;
        dfs(i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    c = computers;
    fill(vis, vis+n, false);
    
    for(int i=0; i<n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        dfs(i);
        ans++;
    }
    
    return ans;
}
//3Ка