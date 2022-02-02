#include <bits/stdc++.h>

using namespace std;

bool is_good(string s){
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        
        if(st.top() == '(' && s[i] == ')') st.pop(); //( ) 라면 
        else st.push(s[i]); // ( ( 라면
    }
    
    //cout << s << " is " << st.empty() << endl;
    if(st.empty()) return true;
    else return false;
}

string func(string w){
    //1
    if(w=="") return "";
    
    string u="",v="";
    int l=0,r=0;
    
    //2
    for(int i=0; i<w.size(); i++){
        if(w[i] == '(') l++;
        else r++;
        u += w[i];
        
        if(l==r){
            if(i != w.size()-1) v=w.substr(i+1);
            break;
        }
    }
    //cout << u << " " << v << endl;
    //3
    if(is_good(u)){ //u가 올바르다면
        u += func(v);   //3-1
    }
    //4
    else{  //u가 올바른 문자열이 아니라면
        string temp = "(";
        temp += func(v);
        temp += ")";
        if(!u.empty()){
            u.erase(0,1);
            u.pop_back();
            for(int i=0; i<u.size(); i++){
                if( u[i] == ')' ) u[i] = '(';
                else u[i] = ')';
            }
        }
        temp += u;
        //cout << "temp : " << temp << endl;
        
        return temp;
    }

    return u;
}

string solution(string p) {
    string answer = "";
    
    answer = func(p);

    return answer;
}
/*
2시반까지
10:31 ~ 11:20
1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
  4-3. ')'를 다시 붙입니다. 
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
  4-5. 생성된 문자열을 반환합니다.
*/