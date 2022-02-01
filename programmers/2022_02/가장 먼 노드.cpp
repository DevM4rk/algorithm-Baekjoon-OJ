#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> e[20001];
    int dist[20001]={};
    
    for(auto a : edge){
        e[a[0]].push_back(a[1]);
        e[a[1]].push_back(a[0]);
    }
    
    fill(dist, dist+n+1, INT_MAX);
    
    queue<int> q;
    q.push(1);
    dist[1]=0;
    
    while(!q.empty()){
        int x = q.front(); q.pop();
        
        for(int i=0; i<e[x].size(); i++){
            int nx = e[x][i];
            if(dist[nx] > dist[x] + 1){
                dist[nx] = dist[x] + 1;
                q.push(nx);
            }
        }
    }
    
    for(int i=1; i<=n; i++) cout << dist[i] << " ";
    
    int far = *max_element(dist+1, dist+1+n);
    
    for(int i=1; i<=n; i++) if(dist[i] == far) answer++;
    
    return answer;
}