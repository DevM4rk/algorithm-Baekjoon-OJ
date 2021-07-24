#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer = 0;
vector<bool> visited(9);
vector<string> u;
vector<string> b;
vector<bool> vis[100];
int viscnt=0;

void dfs(int cnt){
    
    if(cnt == b.size()){

        bool chk = false;
        if(viscnt ==0){
            vis[0] = visited;  
        } 
        else{
            for(int i=0; i<viscnt; i++){
                if(vis[i] == visited) chk = true;
            }
        }
        
        if(!chk){
            vis[viscnt] = visited;  
            viscnt++;
            answer++;
            
            //for(int i=0; i<9; i++) cout << visited[i] << " ";
            //cout << endl;
        }
        
        return;
    }
    
    for(int i=0; i<u.size(); i++){
        if(visited[i]==true || u[i].size() != b[cnt].size()) continue;
        
        bool chk = false;
        for(int j=0; j<b[cnt].size(); j++){
            if(b[cnt][j] == '*'){
                continue;
            }
            else{
                if(u[i][j] != b[cnt][j]) chk = true;
            }
        }
        
        if(!chk){
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
    
    return answer;
}