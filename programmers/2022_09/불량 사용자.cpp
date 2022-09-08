#include <bits/stdc++.h>

using namespace std;

int visited[8];
vector<string> u, b;
set<string> s;

void dfs(int cnt){
    if(cnt == b.size()){
        string str="";
        for(int i=0; i<8; i++){
            str += visited[i] + '0';
        }
        s.insert(str);
        return;
    }
    
    for(int i=0; i<u.size(); i++){
        if (visited[i] || u[i].size() != b[cnt].size()) continue;
        
        bool chk = true;
        for(int j=0; j<b[cnt].size(); j++){
            if(b[cnt][j] == '*') continue;
            if(b[cnt][j] != u[i][j]) chk = false;
        }
        
        if(chk){
            visited[i] = true;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    u = user_id;
    b = banned_id;
    
    dfs(0);
    
    return s.size();
}