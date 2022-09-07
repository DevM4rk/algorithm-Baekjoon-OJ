#include <bits/stdc++.h>

using namespace std;

unordered_map<char,int> m;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0; i<skill.size(); i++){
        m[skill[i]] = i;
    }
    
    for(auto &s : skill_trees){
        int cnt=0;
        bool pass=true;
        
        for(auto &c : s){
            if(m.count(c)){
                if(cnt == m[c]){
                    cnt++;
                }
                else{
                    pass = false;
                    break;
                }
            }
        }
        
        if(pass) answer++;
    }
    
    return answer;
}