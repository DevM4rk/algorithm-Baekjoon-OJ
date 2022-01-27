#include <bits/stdc++.h>

using namespace std;

int Rank(int x){
    if(x==6) return 1;
    else if(x==5) return 2;
    else if(x==4) return 3;
    else if(x==3) return 4;
    else if(x==2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt=0;
    int zerocnt=0;
    
    for(auto a : lottos){
        if(a==0) zerocnt++;
        for(auto b : win_nums){
            if(a==b) cnt++;
        }
    }
    
    int max = Rank(zerocnt+cnt);
    int min = Rank(cnt);
    
    answer.push_back(max);
    answer.push_back(min);
    return answer;
}
/*
10:20 ~ 37
벡터 정렬?
0 0 1 25 31 44  / 1 6 10 19 31 45
맞은거 2개 , win에서 지워버려
0 2개 
*/