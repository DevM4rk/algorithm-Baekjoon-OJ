#include <bits/stdc++.h>

using namespace std;

int n, m, ans=9999;
vector<vector<int>> info;

void dfs(int a, int b, int cnt){
    if(a>=n || b >= m){
        return;
    }
    if(cnt == info.size() && a<n && b<m){
        ans = min(ans, a);
        return;
    }
    if(ans <= a) return;    //나름 시간초과해결
    
    for(int j=0; j<2; j++){
        int at=a, bt=b;
        if(j==0) at += info[cnt][j];
        else bt += info[cnt][j];

        dfs(at,bt,cnt+1);        
    }
}

int solution(vector<vector<int>> infoo,int nn,int mm){
    info = infoo;
    n = nn;
    m = mm;
    
    dfs(0,0,0);
    
    if(ans == 9999) return -1;
    else return ans;
}
/*
7:56 ~ 8:40 오래걸림;
B가 모든 물건을 훔쳐도 흔적을 넘지 않는지 체크
넘는다면 넘는 만큼 A한테 빼줘야함
백트래킹, dfs?

중간에 빼먹는거 없이 더해야하는데

*/