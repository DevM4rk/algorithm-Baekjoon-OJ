#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])) continue;
        
        if(s[i] == 'z'){
            s.erase(s.begin()+i, s.begin()+i+3);
            s[i] = '0';
        }
        else if(s[i] == 'o'){
            s.erase(s.begin()+i, s.begin()+i+2);
            s[i] = '1';
        }
        else if(s[i] == 'e'){
            s.erase(s.begin()+i, s.begin()+i+4);
            s[i] = '8';
        }
        else if(s[i] == 'n'){
            s.erase(s.begin()+i, s.begin()+i+3);
            s[i] = '9';
        }
        else if(s[i] == 't'){
            if(s[i+1] == 'w'){
                s.erase(s.begin()+i, s.begin()+i+2);
                s[i] = '2';    
            }
            else{
                s.erase(s.begin()+i, s.begin()+i+4);
                s[i] = '3';       
            }
        }
        else if(s[i] == 'f'){
            if(s[i+1] == 'o'){
                s.erase(s.begin()+i, s.begin()+i+3);
                s[i] = '4';    
            }
            else{
                s.erase(s.begin()+i, s.begin()+i+3);
                s[i] = '5';       
            }
        }
        else if(s[i] == 's'){
            if(s[i+1] == 'i'){
                s.erase(s.begin()+i, s.begin()+i+2);
                s[i] = '6';    
            }
            else{
                s.erase(s.begin()+i, s.begin()+i+4);
                s[i] = '7';       
            }
        }
        cout << s << endl;
    }    
    
    return stoi(s);
}
/*
4�ð�¥��
7:45 ~ 55 ���� �ʿ� ���� ���ڿ� �ٸ����� ���� �����ϰų� ���� ���ã��, 
*/