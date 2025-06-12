#include <bits/stdc++.h>

using namespace std;

vector<int> sv_del(50);
int sv=1;

int solution(vector<int> p, int m, int k) {
    int answer = 0;
    
    for(int i=0; i<p.size(); i++){
        cout << i << " "<< sv << " "<< "\n";
        sv -= sv_del[i];
        
        if(p[i] >= m*sv){
            int need_sv = p[i] / m +1;
            sv_del[i+k] = need_sv - sv;
            answer += sv_del[i+k];
            sv = need_sv;
        }
    }
    
    
    return answer;
}
/*
현재 서버수
2시에 증설해야되면 저장을
k+2에 개수 저장 벡터 


*/