#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int idx=0;
    
    while(start <= n){
        if(stations[idx]-w <= start && start <= stations[idx]+w){
            start = stations[idx]+w +1;
            idx++;
        }
        else{
            start += 2*w +1;
            answer++;
        }
    }
    
    return answer;
}
/*
특정 숫자에 n=2인 기지국을 설치해야한다는 강박관념에서 벗어나 기지국 포함 좌우 5칸 차지하는 박스로 생각
*/