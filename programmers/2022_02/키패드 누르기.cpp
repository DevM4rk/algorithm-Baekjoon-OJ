#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string ans = "";
    int lx=3,ly=0, rx=3,ry=2;
    
    for(auto n : numbers){
        if(n==0) n=10;
        int x=n/3;
        if(n==1 || n==4 || n==7){
            lx=x; ly=0;
            ans+="L";
        }
        else if( n==3 || n==6 || n==9){
            rx=x-1; ry=2;
            ans+="R";
        }
        else{ // (n,1)
            int l=abs(x-lx) + abs(1-ly);
            int r=abs(x-rx) + abs(1-ry);
            cout << x << " " << lx << " " << ly << " " << rx << " " << ry << endl;
            cout << l << " " << r << endl;
            if(l < r){    //크면 멀리있다는 뜻
                lx=x; ly=1;
                ans+="L";
            }
            else if(l > r){
                rx=x; ry=1;
                ans+="R";
            }
            else{
                if(hand == "left"){
                    lx=x; ly=1;
                    ans+="L";                  
                }
                else{
                    rx=x; ry=1;
                    ans+="R";  
                }
            }
        }
    }
    
    return ans;
}
/*
4시간짜리
12:41 ~ 25  / 45분걸림
*/