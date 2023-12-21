#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int ans=1, ptr = 0;
    for(int i=1; i<=30000; i++){
        string str = to_string(i);
        for(int j=0; j<str.size(); j++){
            if(str[j] == s[ptr]){
                ptr++;
            }
        }

        if(ptr == s.size()){

            cout << i;
            break;
        }
    }
}