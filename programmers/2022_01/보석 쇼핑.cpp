#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> s(gems.begin(), gems.end());
    int size = s.size();
    
    unordered_map<string, int> m;
    int ansst=0, ansend=100000;
    int st=0, end=0;
    int cnt=0;
    bool loc = false;
    
    while(st <= end && end < gems.size()){
        if(loc){
            m[gems[st-1]]--;
            if(m[gems[st-1]] == 0) cnt--;
        }
        else{
            m[gems[end]]++;
            if(m[gems[end]] == 1) cnt++;
        }
        //cout << st << " " << end << " " << cnt << endl;
        
        if(cnt == size){
            if(ansend - ansst > end - st){
                cout << st << " " << end << endl;
                ansst = st;
                ansend = end;
            }
            if(end-st+1 == size) break;
        }
        
        if(cnt == size){
            st++;
            loc = true;
        }
        else{
            end++;
            loc = false;
        }
    }
    
    answer.push_back(ansst+1);
    answer.push_back(ansend+1);
    
    return answer;
}
/*
9:10 ~ 10:00
투포인터!!!
와 이걸 푸네 감격..
*/