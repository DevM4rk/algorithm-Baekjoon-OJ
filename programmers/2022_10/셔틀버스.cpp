#include <bits/stdc++.h>

using namespace std;

string itos(int n){
    string str="";
    string h = to_string(n/60);
    string s = to_string(n%60);
    if(n/60 < 10) str+='0';
    str+=h;
    str+=':';
    if(n%60 < 10) str+='0';
    str+=s;
    
    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    priority_queue<int,vector<int>, greater<int>> pq;
    
    for(auto &a : timetable){
        int h = stoi(a.substr(0,2)) * 60;
        int s = stoi(a.substr(3,2));
        if(h+s >1080) continue;
        pq.push(h+s);
    }
    
    for(int i=0; i<n; i++){
        int bus = 540+i*t;
        int cnt=0;
        int x=540;
        while(!pq.empty() && (cnt < m && pq.top() <= bus)){
            x = pq.top(); pq.pop();
            cnt++;
            cout << cnt << " " << x << endl;
        }
        
        if(i == n-1){
            if(cnt == m)
                answer = itos(x-1);
            else if(cnt < m)
                answer = itos(bus);
        }
    }
    
    return answer;
}