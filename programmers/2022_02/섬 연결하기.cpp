#include <bits/stdc++.h>

using namespace std;

int p[101]={};

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(), costs.end(), cmp);
    iota(p, p+n, 0);
    
    for(int i=0; i<costs.size(); i++){
        int st = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        
        int x = find(st);
        int y = find(end);
        
        if(x==y) continue;
        
        p[x] = y;
        answer+=cost;
    }
    
    return answer;
}