#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int ans=s.size();
    
    for(int i=1; i<=s.size()/2; i++){
        string temp="", t="", nt=""; int cnt=1;
        //cout << i << endl;
        
        for(int j=0; j<s.size(); j+=i){
            nt = s.substr(j,i);
            //cout << j << " " << t << " " << nt << endl;
            
            if(nt == t) cnt++;
            else{
                if(cnt>=1){
                    if(cnt != 1) temp += to_string(cnt);
                    temp += t;
                    cnt=1;
                }
                t = nt;
            }
            
            if(j+i >= s.size()){
                if(cnt>=1){
                    if(cnt != 1) temp += to_string(cnt);
                    temp += t;
                }
            }
        }
        //cout << "temp : " << temp << endl;
        int ts = temp.size();
        ans = min(ans, ts);
    }
    return ans;
}
/*
5�ð����� ������~ 2�ùݱ���
9:34start ~ 10:30
������ ũ���� ���� ������ ª�� ��� ����
���ڿ� �տ������� ������ ���̸�ŭ �߶����
*/