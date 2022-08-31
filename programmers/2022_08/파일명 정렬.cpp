#include <bits/stdc++.h>

using namespace std;

struct file{
    string head;
    int num;
    int idx;
};

vector<file> v;

bool cmp (const file &a, const file &b){
    if(a.head == b.head){
        if(a.num == b.num){
            return a.idx < b.idx;
        }
        return a.num < b.num;
    }
    return a.head < b.head;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int idx =0;
    for(auto str : files){
        string head="", num="";
        int numstart = 0, check = 0;
        
        for(int i=0; i<str.size(); i++){
            if(check == 0 && isdigit(str[i])){
                head = str.substr(0,i);   // 대문자 -> 소문자로 변경해야함 나중에
                numstart = i;
                check = 1;
                //cout << head << endl;
            }
            if(check == 1 && !isdigit(str[i])){
                num = str.substr(numstart, i-numstart);
                //cout << num << endl;
                break;
            }
        }
        // tail 이 없어서 위의 num if문이 작동 안하는 경우도 생각해줘야함
        if(num == "") num = str.substr(numstart);
        
        
        for(int i=0; i<head.size(); i++){
            if(head[i] >= 'a') head[i] = head[i] - ('a' - 'A');
        }
        
        int n = stoi(num);
        
        //cout << head << " " << n << " " << idx << endl;
        
        file F;
        F.head = head;
        F.num = n;
        F.idx = idx;
        
        v.push_back(F);
        
        idx++;
    }
    
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++){
        answer.push_back(files[v[i].idx]);
    }
    
    return answer;
}