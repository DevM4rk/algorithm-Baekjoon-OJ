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
    if(ans <= a) return;    //���� �ð��ʰ��ذ�
    
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
7:56 ~ 8:40 �����ɸ�;
B�� ��� ������ ���ĵ� ������ ���� �ʴ��� üũ
�Ѵ´ٸ� �Ѵ� ��ŭ A���� �������
��Ʈ��ŷ, dfs?

�߰��� ���Դ°� ���� ���ؾ��ϴµ�

*/