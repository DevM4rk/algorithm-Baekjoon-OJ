#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int ans = 0;
    vector<vector<bool>> d(n+1, vector<bool> (n+1, false));
    
    for(auto r : results) d[r[0]][r[1]] = true; 
    
    // for(int i=1; i<=n; i++){   
    //     for(int j=1; j<=n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i=1; i<=n; i++){    //경유지
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(d[j][i] && d[i][k]){
                    d[j][k] = true;
                }
            }
        }
    }
    
    // cout << endl;
    // for(int i=1; i<=n; i++){   
    //     for(int j=1; j<=n; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i=1; i<=n; i++){   
        int cnt=0;
        for(int j=1; j<=n; j++){
            if(d[i][j] || d[j][i]){
                cnt++;
            }
        }
        if(cnt==n-1) ans++;
    }

    
    
    return ans;
}
/*
플로이드 와샬 적용 할 경우
*/