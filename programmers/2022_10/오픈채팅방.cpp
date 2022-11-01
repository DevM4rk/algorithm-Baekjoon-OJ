#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    vector<pair<string,string>> v;
    
    for(auto &s : record){
        stringstream ss;
        ss.str(s);
        string cmd,uid,name;
        ss >> cmd >> uid >> name;
        
        if(cmd != "Leave"){
            m[uid]=name;
        }
        
        if(cmd != "Change"){
            v.push_back({cmd,uid});
        }
    }
    
    for(auto &a : v){
        string str = m[a.second];
        
        if(a.first == "Enter"){
            str += "님이 들어왔습니다.";
        }
        else{
            str += "님이 나갔습니다.";
        }
        
        answer.push_back(str);
    }
    
    return answer;
}
/*
uid,닉네임 따로 관리하는 map
enter,uid를 담는 vector
*/