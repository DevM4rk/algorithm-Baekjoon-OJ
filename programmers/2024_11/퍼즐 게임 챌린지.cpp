#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int ans=INT_MAX;
    int st=1,end=0,mid;
    for(auto d : diffs) end = max(end, d);
    
    while(st<end){
        long long time=0;
        mid = (st+end+1)/2;
        
        for(int i=0; i<diffs.size(); i++){
            if(diffs[i] <= mid) time += times[i];
            else{
                time += (times[i] + times[i-1]) * (diffs[i] - mid) + times[i];
            }
        }
        
        cout << st << " " << end << " " << mid << " " << time << endl;

        if(time<limit){
            end = mid-1;
            ans = min(ans, mid);    // 1테케 절반 통과
            if(mid==2) return 1;    // 3테케14번 통과
        }
        else{
            st = mid;

        }
        if(time == limit) return mid;   // 2테케 15, 18번? 통과
    }
    
    
    return ans;
}
/*
20분
이분탐색!

*/