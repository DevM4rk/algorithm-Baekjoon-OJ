#include <bits/stdc++.h>

using namespace std;

int cal(string str){
    string hs,ms,ss; int h,m,s;
    hs = str.substr(0,2);
    h = stoi(hs);
    ms = str.substr(3,2);
    m = stoi(ms);
    ss = str.substr(6,2);
    s = stoi(ss);
    
    //cout << hs << " " << ms << " " << ss << endl;
    return h*3600 + m*60 + s;
}

string totime(int x){
    string h,m,s,ret;
    h = to_string(x/3600);
    m = to_string((x%3600) / 60);
    s = to_string((x%3600) % 60);
    if(h.size()==1) h = '0' + h;
    if(m.size()==1) m = '0' + m;
    if(s.size()==1) s = '0' + s;
    ret = h + ":" + m + ":" + s;
    //cout << h << " " << m << " " << s << endl;
    return ret;
}

string solution(string playt, string advt, vector<string> logs) {
    string answer = "";
    int pt = cal(playt);
    int at = cal(advt);
    //cout << pt << " " << at << endl;
    
    //sort(logs.begin(), logs.end());
    
    int arr[360000]={};
    for(auto str : logs){
        int st = cal(str);
        int end = cal(str.substr(9));
        //cout << st << " " << end << endl;
        
        arr[st]++;
        arr[end]--;
    }
    
    for(int i=0; i<360000; i++) arr[i] += arr[i-1];
    
    long long maxsum=0;
    long long sum=0;
    int res;
    
    for(int i=0; i<at; i++)
        sum += arr[i];
    
    maxsum = sum;
    
    for(int i=at-1; i<pt; i++){
        sum += arr[i] - arr[i-at];
        
        if(maxsum < sum){
            maxsum = sum;
            res = i-at +1;
        }
    }
    
    answer = totime(res);
    return answer;
}
/*
12:45
´©ÀûÇÕ
   log sort

*/