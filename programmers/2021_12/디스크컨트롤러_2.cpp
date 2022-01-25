#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int solution(vector<vector<int>> jobs) {
    int answer = 0, i = 0, start = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    
    sort(all(jobs));
        
    while(!pq.empty() || i < jobs.size()){
        
        if( i < jobs.size() && start >= jobs[i][0]){
            pq.push({jobs[i][1], jobs[i][0]});
            i++;
            continue;
        }
        
        if(!pq.empty()){
        int time = pq.top().first;
        int wait = pq.top().second;
        pq.pop();
        
        start += time;
        answer += start - wait;
        }
        else{
            start = jobs[i][0];
        }
    }
    
    return answer / jobs.size();
}

/*
요청되는시점이 낮은순부터 정렬하는 pq와
소요시간이 낮은 순부터 정렬하는 pq

*/