#include <bits/stdc++.h>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int w2 = w*2;
    
    
    int Under = num / w2;
    int UnrealNum = num % w2;
    if(UnrealNum == 0){
        Under --;
        UnrealNum = w2;
    }
    
    int Size = n / w2;
    int Box = n % w2;
    if(Box == 0) {
        Size --;
        Box = w2;
    }
    
    
    if(Size > Under){
        answer+=(Size-Under)*2;
    }
    
    
    int row = 0;  // 0,1
    int col = 0;
    if(UnrealNum <= w){
        row = 0;
        col = UnrealNum;
    }
    else{
        row = 1;
        col = w+1 - (UnrealNum -w);
    }
    
    int PlusNextNum = w2+1 - UnrealNum - col; // row =0일때만 사용
    
    
    if(row == 0){
        if(col <= Box) answer++;
        if(col + PlusNextNum <= Box) answer++;
    }
    else{
        if(UnrealNum <= Box) answer++;
    }
    
    
    return answer;
}