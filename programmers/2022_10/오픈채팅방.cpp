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
            str += "���� ���Խ��ϴ�.";
        }
        else{
            str += "���� �������ϴ�.";
        }
        
        answer.push_back(str);
    }
    
    return answer;
}
/*
uid,�г��� ���� �����ϴ� map
enter,uid�� ��� vector
*/