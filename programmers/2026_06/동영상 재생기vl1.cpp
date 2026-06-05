#include <bits/stdc++.h>

using namespace std;

int cal(string s){
    int m = stoi(s.substr(0,2));
    int se = stoi(s.substr(3,2));
    return m*60 + se;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int vlen = cal(video_len);
    int ps = cal(pos);
    int st = cal(op_start);
    int end = cal(op_end);
    if(st <= ps && ps <= end) ps = end;
    
    for(auto c : commands){
        if (c == "next"){
            ps+=10;
            if(ps > vlen) ps = vlen;
        }
        else{
            ps-=10;
            if(ps < 0) ps=0;
        }
        
        
        if(st <= ps && ps <= end) ps = end;
    }
    string min = to_string(ps/60);
    string sec = to_string(ps%60);
    if(min.size() == 1) min = '0' + min;
    if(sec.size() == 1) sec = '0' + sec;
    answer = min + ':' + sec;
    return answer;
}
/*
3:19
*/