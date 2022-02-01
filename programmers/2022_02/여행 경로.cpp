#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

unordered_map<string, vector<string>> m;
map<pair<string,string>, int> vis;
vector<string> ans, v;
int n;

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
        cout << "check" << endl;
        ans = v;
        return;
    }
    
    // for(auto i : v) cout << i << " ";
    // cout << endl;
    
    for(int i=0; i<m[s].size(); i++){
        string ns = m[s][i];
        // cout << s << " " << ns << " " << vis[{s,ns}] << endl;
        if(vis[{s,ns}]==0) continue;
        vis[{s,ns}]--;
        v.push_back(ns);
        
        dfs(ns, cnt+1);
        vis[{s,ns}]++;
        v.pop_back();
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    for(auto t : tickets){
        m[t[0]].push_back(t[1]);
        vis[{t[0],t[1]}]++;
    }
    
    v.push_back("ICN");
    dfs("ICN", 0);
    
    return ans;
}
