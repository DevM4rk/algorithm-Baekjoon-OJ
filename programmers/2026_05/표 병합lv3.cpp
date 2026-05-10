#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> board(51, vector<string> (51) );
vector<vector<pair<int,int>>> parent(51, vector<pair<int,int>> (51) );
map< pair<int,int>, vector<pair<int,int>> > m;

pair<int,int> find(int r, int c){ 
    pair<int,int> p = parent[r][c]; 
    auto [pr,pc] = parent[r][c]; 
    if( pr != r || pc != c) p = find(pr,pc); 
    parent[r][c] = p; 
    return p;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i=0; i< 51; i++){
        for(int j=0; j<51; j++){
            parent[i][j] = {i,j};
            m[{i,j}].push_back({i,j});
        }
    }
    
    
    for(auto c : commands){
        
        // for(int i=0; i< 5; i++){
        //     for(int j=0; j<5; j++){
        //         cout << parent[i][j].first << parent[i][j].second<< " ";
        //     }
        //     cout << endl;
        // } 
        // for(int i=0; i< 5; i++){
        //     for(int j=0; j<5; j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
        stringstream stream(c);
        
        vector<string> v(5);
        for(auto &a : v) stream >> a;
        
        // for(auto a : v) cout << a << " ";
        // cout << "\n";
        
        if(v[0] == "UPDATE"){
            if(v[3] != ""){
                int r = stoi(v[1]), c = stoi(v[2]);
                string value = v[3];
                
                pair<int,int> p = find(r,c);
                r = p.first;
                c = p.second;
                board[r][c] = value;    
            }
            else{
                string value1 = v[1], value2 = v[2];
                
                for(int i=0; i< 51; i++){
                    for(int j=0; j<51; j++){
                        if(board[i][j] == value1) board[i][j] = value2;
                    }
                }
                
            }
        }
        else if(v[0] == "MERGE"){
            int r1 = stoi(v[1]), c1 = stoi(v[2]), r2 = stoi(v[3]), c2 = stoi(v[4]);
            
            pair<int,int> p1 = find(r1,c1);
            pair<int,int> p2 = find(r2,c2);
            
            if(p1 != p2){
                parent[p2.first][p2.second] = p1;
                for(auto a : m[p2]){
                    m[p1].push_back(a);
                }
                m[p2].clear();
                
                if(board[p1.first][p1.second] == "") 
                    board[p1.first][p1.second] = board[p2.first][p2.second];
                
            }
        }
        else if(v[0] == "UNMERGE"){
            int r = stoi(v[1]), c = stoi(v[2]);
            
            pair<int,int> p = find(r,c);
            int pr = p.first;
            int pc = p.second;
            string value = board[pr][pc];
            for(auto a : m[p]){
                parent[a.first][a.second] = a;
                board[a.first][a.second] = "";
                if(a==p) continue;
                m[a].clear();
                m[a].push_back(a);
            }
            m[p].clear();
            m[p].push_back(p);
            board[r][c] = value;
            
        }
        else if(v[0] == "PRINT"){
            int r = stoi(v[1]), c = stoi(v[2]);
                            
            pair<int,int> p = find(r,c);
            r = p.first;
            c = p.second;
            if( board[r][c] == "" ) answer.push_back("EMPTY");
            else answer.push_back(board[r][c]);
        }
    }
    
    return answer;
}