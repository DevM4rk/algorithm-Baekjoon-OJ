#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    char bef='0';
    int cnt=0,ans=0;

    for(auto c : s){
        if(bef == '('){
            if(c == '('){   // ((
                cnt++;
            }
            else{           // ()
                ans+=cnt;
            }
        }
        else if(bef == ')'){
            if(c == '('){   // )(

            }
            else{           // ))
                cnt--;
                ans++;
            }
        }
        bef = c;
    }   
    cout << ans;
}