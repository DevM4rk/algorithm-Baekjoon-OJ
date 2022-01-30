#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    stack<int> st;
    set<int> a;
    
    for(int i=0; i<n; i++) a.insert(i);
    
    auto it = a.find(k);
    
    for(auto s : cmd){
        if(s[0] == 'C'){
            st.push(*it);
            it = a.erase(it);
            if(a.end() == it) it--;
        }
        else if(s[0] == 'Z'){
            a.insert(st.top());
            st.pop();
        }
        else{
            stringstream ss; ss.str(s);
            int num;
            ss >> s >> num;
            if(s == "U"){
                it = prev(it, num); //while(num--) it--;
            }
            else if(s == "D"){ // D
                it = next(it, num); //while(num--) it++;
            }
        }
        
        //for(auto i : a) cout << i << " ";
        //cout << endl;
        //cout << *it << endl;
    }
    
    for(auto v : a) answer[v] = 'O';
    return answer;
}
/*
9:33 ~ 
중간 삽입삭제가 용이한 list 사용?
Z는 스택으로 구현
*/