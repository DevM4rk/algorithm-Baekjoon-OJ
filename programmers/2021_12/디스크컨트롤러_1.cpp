#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

typedef pair<int,int> pii;

int solution(vector<vector<int>> jobs) {
    int answer = 0, alltime = 0, start = 0;
    priority_queue<pii, vector<pii>, greater<pii>> jobs_pq, pq;
    
    for(auto &a : jobs)
        jobs_pq.push({a[0], a[1]});
    
    pq.push({jobs_pq.top().second, jobs_pq.top().first});// pq의 first가 소요시간
    start = jobs_pq.top().first;
    jobs_pq.pop();
    
    while(!pq.empty()){
        int time = pq.top().first;
        int wait = pq.top().second;
        pq.pop();
        
        start += time;
        alltime += start - wait;
        
        while(!jobs_pq.empty() && start >= jobs_pq.top().first){
            pq.push({jobs_pq.top().second, jobs_pq.top().first});
            jobs_pq.pop();
        }
        
        if(pq.empty() && !jobs_pq.empty()){
            pq.push({jobs_pq.top().second, jobs_pq.top().first});
            start = jobs_pq.top().first;
            jobs_pq.pop();
        }
    }
    
    answer = alltime / jobs.size();
    return answer;
}

/*
요청되는시점이 낮은순부터 정렬하는 pq와
소요시간이 낮은 순부터 정렬하는 pq

*/