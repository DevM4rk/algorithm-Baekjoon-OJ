#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i=0; i<progresses.size(); i++){
        int res = 100-progresses[i];
        if (res % speeds[i] != 0) res += speeds[i];
        q.push(res/speeds[i]);
    }
    
    int cnt = 0;
    int d = q.front();
    
    while(!q.empty()){

        if(q.front() <= d){
            cnt++;
            q.pop();
        }
        else{
            answer.push_back(cnt);    
            cnt =0;
            d = q.front();
        }
    }
    
    answer.push_back(cnt);    
    
    return answer;
}