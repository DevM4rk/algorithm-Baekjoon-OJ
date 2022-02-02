#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    int n = routes.size();
    sort(routes.begin(), routes.end());
    for(auto a : routes) cout << a[0] << " " << a[1] << endl;
    
    int st=routes[0][0], end=routes[0][1];
    for(int i=1; i<n; i++){
        int x = routes[i][0];
        int y = routes[i][1];
        
        if(end < x){
            answer++;
            st = x;
            end= y;
        }
        else{
            if(st > x) st = x;
            if(y < end) end = y;
        }
    }
    
    return answer;
}