#include <bits/stdc++.h>

using namespace std;

bool is_good(string s){
    stack<char> st;
    
    for(int i=0; i<s.size(); i++){
        if(st.empty()){
            st.push(s[i]);
            continue;
        }
        
        if(st.top() == '(' && s[i] == ')') st.pop(); //( ) ��� 
        else st.push(s[i]); // ( ( ���
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
    if(is_good(u)){ //u�� �ùٸ��ٸ�
        u += func(v);   //3-1
    }
    //4
    else{  //u�� �ùٸ� ���ڿ��� �ƴ϶��
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
2�ùݱ���
10:31 ~ 11:20
1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
2. ���ڿ� w�� �� "�������� ��ȣ ���ڿ�" u, v�� �и��մϴ�. ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 
3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�. 
  3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�մϴ�. 
4. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�"�� �ƴ϶�� �Ʒ� ������ �����մϴ�. 
  4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�. 
  4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�. 
  4-3. ')'�� �ٽ� ���Դϴ�. 
  4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
  4-5. ������ ���ڿ��� ��ȯ�մϴ�.
*/