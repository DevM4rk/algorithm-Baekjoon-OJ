#include <bits/stdc++.h>

using namespace std;

bool cmp(const string& a, const string& b){
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    
    for(auto &a : numbers) v.push_back(to_string(a));
        
    sort(v.begin(), v.end(), cmp);
    
    for(auto &a : v) answer += a;
    
    if (answer[0] == '0')  answer = "0";
    return answer;
}

