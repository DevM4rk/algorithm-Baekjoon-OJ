#include <iostream>
#include <deque>

using namespace std;

int T,n;
string p,arr;
deque<int> dq;
bool check = true; //true : R2,  false : R1

void print(){

}
/*
R일 경우

출력할때도 R의 경우에 따라서 front or back 순서로

D일 경우
dq 가 비어있을 때 error 발생

R의 경우에 따라서 front or back pop
 

*/

void solve(){
    for(int i=0; p[i]>0 ;i++){
        if( p[i] == 'R'){
            check = !check;
        }
        else if( p[i] == 'D'){
            if(check){
                
            }
            else{

            }
        }
    }

    print();
}

int main(){
    cin >> T;

    while(T--){
        cin >> p >> n >> arr;

        int f=1,b;
        string str_temp;
        arr.pop_back();
        arr.push_back(',');
        while( (b = arr.find(',', f))!=std::string::npos){
            int len = b-f;
            if( len == 0 ) break;
            str_temp = arr.substr(f, len);
            dq.push_back(atoi(str_temp.c_str()));
            f = b+1;
        }

        solve();

        dq.clear();
    }
}
