#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string,set<string>> m;
    unordered_map<string,int> idmap;
    
    for(auto r : report){
        int sp = r.find(' ');
        string s1 = r.substr(0,sp);
        string s2 = r.substr(sp);
        //cout << s1 << " "<< s2 << endl;
        m[s2].insert(s1);
    }
    
    for(auto [a,s] : m)
        if(s.size() >= k)
            for(auto id : s)
                idmap[id]++;
    
    for(auto id : id_list)
        answer.push_back(idmap[id]);
    
    return answer;
}