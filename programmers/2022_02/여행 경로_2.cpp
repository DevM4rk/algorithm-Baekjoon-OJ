#include <string>
#include <vector>

using namespace std;

vector<vector<string>> t;
vector<string> ans, v;
int n;
int vis[10000]={};

bool cmp(){
    if(ans.empty()) return true;

    for(int i=0; i<n; i++){
        if(v[i] == ans[i]) continue;
        else if(v[i] < ans[i]) return true;
        else return false;
    }
}

void dfs(string s, int cnt){
    if(cnt == n && cmp()){
        ans = v;
        return;
    }
    
    for(int i=0; i<n; i++){
        if(vis[i] || s != t[i][0]) continue;
        vis[i]=1;
        v.push_back(t[i][1]);
        
        dfs(t[i][1], cnt+1);
        vis[i]=0;
        v.pop_back();
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    t = tickets;
    
    v.push_back("ICN");
    dfs("ICN", 0);
    
    return ans;
}