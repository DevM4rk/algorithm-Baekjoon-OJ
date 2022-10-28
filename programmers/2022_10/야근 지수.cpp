#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    priority_queue <long long> pq;
    for(auto &a : works){
        sum += a;
        pq.push(a);
    }
    if(sum <= n) return 0;
    
    for(int i=0; i<n; i++){
        auto x = pq.top(); pq.pop();
        x--;
        if(x !=0 ){
            pq.push(x);
        }
    }

    while(!pq.empty()){
        auto x = pq.top(); pq.pop();
        answer += x*x;
    }
    
    return answer;
}