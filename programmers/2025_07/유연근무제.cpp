#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
       
    for(int i=0; i<schedules.size(); i++){
        int s = schedules[i];

        bool late = false;
        int cnt = startday-1;

        for(auto t : timelogs[i]){
            cnt++;
            if(cnt >7) cnt=1;
            if(cnt == 6 || cnt == 7) continue;
            
            int temp = t-10;
            if(t/100 != temp/100) temp -= 40;
            
            if(s < temp) {
                late = true;
                break;
            }
        }
        
        if(!late) answer++;
    }
    
    return answer;
}
