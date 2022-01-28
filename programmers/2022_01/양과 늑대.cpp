#include <bits/stdc++.h>

using namespace std;

int ans = 1;
bool vis[18]={};
vector<int> info;
vector<vector<int>> e;

void dfs(int sheep, int wolf){
    
    //cout << "f " <<sheep << " " << wolf << endl;

    for(int i=e.size()-1; i>=0; i--){
        int now = e[i][0];
        int next = e[i][1];
        //cout << now << " " << next << endl;
        
        if(vis[now] && !vis[next]){     //���� �湮�Ǿ� �ְ�, ������ �湮 �ȵ� ���� ��� 
            //cout << "pass " << info[next] << endl;
            
            if(info[next] == 0){
                sheep++;
                vis[next] = true;
                ans = max(ans, sheep);
                
                dfs(sheep, wolf);
                sheep--;
                vis[next] = false;
            }
            else{   // ������ ���
                if(sheep > wolf + 1){
                    wolf++;
                    vis[next] = true;
                    
                    dfs(sheep, wolf);
                    wolf--;
                    vis[next] = false;
                }
            }
        }
    }
}

int solution(vector<int> inf, vector<vector<int>> edges) {
    e = edges;
    info = inf;
    vis[0] = true;
    sort(e.begin(), e.end());
    
    dfs(1, 0);
    
    return ans;
}