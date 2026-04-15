#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> priv) {
    vector<int> answer;
    
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8));
    
    map<char,int> m;
    for(auto t : terms){
        char term = t[0];
        int term_month = stoi(t.substr(2));
        m[term] = term_month;
    }
    
        
    for(int i=0; i<priv.size(); i++){
        bool check = false;
        int p_year = stoi(priv[i].substr(0,4));
        int p_month = stoi(priv[i].substr(5,2));
        int p_day = stoi(priv[i].substr(8,2));
        char p_term = priv[i][11];
   
        p_month += m[p_term];
        if(p_month > 12){
            int a = p_month /12;
            if(p_month %12 == 0) a-=1;
            p_month = p_month %12;
            if(p_month == 0) p_month=12;
            p_year += a;
            cout << a << " " << endl;
        }
        cout << year << " " << month << " " << day << endl;
        cout << p_year << " " << p_month << " " << p_day << endl;
        
        if(year == p_year){
            if(month == p_month){
                if(day >= p_day){
                    check = true;
                }
            }
            else if(month > p_month){
                check = true;
            }
        }
        
        
        if(year < p_year){
            continue;
        }
        else if(year > p_year){
            check = true;
        }
        
        if(check){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}
