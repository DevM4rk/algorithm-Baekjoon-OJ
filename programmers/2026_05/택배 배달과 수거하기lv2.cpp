#include <bits/stdc++.h>

using namespace std;

long long solution(int cap, int n, vector<int> del, vector<int> pic) {
    long long answer = 0;

    bool check = false;
    for(auto a : del){ 
        if(a!=0) check = true;
    }
    for(auto a : pic){ 
        if(a!=0) check = true;
    }
    if(!check) return 0;
    

    int d = n-1, p = n-1;
    int t=2;
    while(!(d==0 &&del[d] ==0) || !(p==0 &&pic[p] ==0)){
        t--;
        int a = max(d,p);
        answer += (a+1)*2;
        
        //cout << d << " " << p << " " << del[d] << " " << pic[p] << endl;
        
        del[d] -= cap;
        int temp;
        while(del[d] < 0){
            temp = del[d];
            del[d] = 0;
            
            if(d>0){
                d--;
                del[d] += temp; 
            }
        }
        
        while(del[d] ==0 && !d==0){
            d--;
        }
        
        pic[p] -= cap;
        
        while(pic[p] < 0){
            temp = pic[p];
            pic[p] = 0;
            
            if(p>0){
                p--;
                pic[p] += temp;   
            }
        }
        
        while(pic[p] ==0 && !p==0){
            p--;
        }
    }
    return answer;
}
/*
최대값은
cap 1일때 n 100,000 원소값 50
5,000,000 번
끝으로 배달 가는길에 배달할게있으면 배달해야함
3 1 2
0 4 0 의 경우 1주고 2주고 돌아오는식

수거는 끝에서부터 계속 가져오면됨
배달보다 수거가 더 뒤에 많은경우도있으니 주의
9 0 0
0 0 10

*/