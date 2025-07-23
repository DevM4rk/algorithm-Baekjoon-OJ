#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;

    vector<int> a(30, 1);
    a[0] = a[1] = a[2] = a[3] = a[4] = 0;
    

    do{
        bool check = true;
        
        for(int i=0; i< q.size(); i++){
            int cnt=0;
            
            for(auto num : q[i])
                if(a[num-1] == 0) cnt++;
            
            if(cnt != ans[i]){
                check = false;
                break;
            }
            
        }
        
        if(check) answer++;
        
    }while(next_permutation(a.begin(), a.begin()+n));
    
    
    return answer;
}