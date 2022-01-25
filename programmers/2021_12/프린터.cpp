#include <string>
#include <vector>
#include <queue>
 
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i=0; i<priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
        pq.push(priorities[i]);
    }
    
    while(!q.empty()) {
        int i = q.front().first;
        int p = q.front().second;
        q.pop();
        
        if(p == pq.top()) {
            pq.pop();
            answer++;
            
            if(i == location) break;
            
        } 
        else {
            q.push(make_pair(i,p));
        }
    }
    
    return answer;
}
