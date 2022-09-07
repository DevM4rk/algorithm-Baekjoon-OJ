#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int cnt;
    int i=0;
    queue<pair<int,int>> q;
    int sum=0;
    
    for(cnt=0; ; cnt++){
        if(i == truck_weights.size() && sum==0) break;
        
        if(q.front().second + bridge_length == cnt){
            sum -= q.front().first;
            q.pop();
        }
        
        if(i<truck_weights.size()){
            int tw = truck_weights[i];
            if(sum + tw <= weight){
                sum += tw;
                i++;
                q.push({tw, cnt});
            }
        }
        
        //cout << cnt << " " << sum << endl;
    }
    
    return cnt;
}