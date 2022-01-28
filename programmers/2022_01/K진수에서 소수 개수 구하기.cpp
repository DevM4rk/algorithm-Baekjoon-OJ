

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

    
    string s=""; long long t=0;     // 2���� ���� ��� int�� �Ѵ� ���ڰ� �ð�� 
    for(int i=0; i<num.size(); i++){
        if(num[i] -'0' == 0 && !s.empty()){ // ""�� �Ѵ��ؼ� 0�� �ƴ��� ���� stoll ������
                
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
2022 KAKAO BLIND RECRUITMENT 5�ð� Ŭ���� �غ���
9�� 30�б���!
4:50�� ���� ~ 6�� 5�� Ŭ ��
10�� 2�����Ұ��
10 �������� �������� �����ϱ�
5 0 / 3 1
2 1 / 1 0
1 0 / 0 1
0 1
*/