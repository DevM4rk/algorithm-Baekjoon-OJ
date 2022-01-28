

#include <bits/stdc++.h>

using namespace std;

bool prim(long long x){
    if(x<2) return false;
    
    for(long long i=2; i<=sqrt(x); i++){
        if(x % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string num;
    
    while(n>0){
        num += to_string(n%k);
        n = n/k;
    }
    reverse(num.begin(), num.end());

    
    string s=""; long long t=0;     // 2진법 같이 길면 int를 넘는 숫자가 올경우 
    for(int i=0; i<num.size(); i++){
        if(num[i] -'0' == 0 && !s.empty()){ // ""을 한다해서 0이 아님을 주의 stoll 에러남
                
            cout << s << endl;
            t = stoll(s);
            if(prim(t)) answer++;
            s="";
        }
        else{
            s+=num[i];
        }
    }
    if(!s.empty()){
        t = stoll(s);
        if(prim(t)) answer++;
    }
    
    return answer;
}
/*
2022 KAKAO BLIND RECRUITMENT 5시간 클리어 해보자
9시 30분까지!
4:50분 시작 ~ 6시 5분 클 ㅠ
10을 2진법할경우
10 나머지를 역순으로 나열하기
5 0 / 3 1
2 1 / 1 0
1 0 / 0 1
0 1
*/