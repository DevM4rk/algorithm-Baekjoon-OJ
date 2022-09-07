#include <bits/stdc++.h>

using namespace std;

int one, zero;
vector<int> answer;
vector<vector<int>> arr;

void dfs(int x,int y, int ex, int ey, int n){
    if(n==0) return;
    
    //cout << x << " " << y << " " << ex << " " << ey << " " << n << endl;
    int cnt=0;
    int value = arr[x][y];
    for(int i=x; i<ex; i++){
        for(int j=y; j<ey; j++){
            if(arr[i][j]==value) cnt++;
        }
    }
    
    if(cnt == n*n){
        if(value==1) one++;
        else zero++;
        //cout << arr[x][y] << endl;
    }
    else{
        int N = n/2;
        dfs(x, y, ex-N, ey-N, N);
        dfs(x, y+N, ex-N, ey, N);
        dfs(x+N, y, ex, ey-N, N);
        dfs(x+N, y+N, ex, ey, N);
    }
}

vector<int> solution(vector<vector<int>> ar) {
    int n = ar.size();
    arr = ar;
    
    dfs(0,0,n,n,n);
    
    answer.push_back(zero);
    answer.push_back(one);
    return answer;
}