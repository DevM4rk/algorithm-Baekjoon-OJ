#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    int a;
    vector<int> v;
    stringstream ss;
    ss.str(s);
    while(ss >> a){
        v.push_back(a);
    }
    answer += to_string(*min_element(v.begin(), v.end()));
    answer += ' ';
    answer += to_string(*max_element(v.begin(), v.end()));
    return answer;
}