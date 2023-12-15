#include <bits/stdc++.h>

using namespace std;

int main(){
    
    while(true){
        bool pass = false;
        string s; cin >> s;
        if(s == "end") break;

        for(auto c : s){
            if(strchr("aeiou", c)) pass = true;
        }

        if(pass){
            int mo=0,ja=0;
            for(int i=0; i<s.size(); i++){
                if(strchr("aeiou", s[i])){
                    mo++;
                    ja=0;
                }
                else{
                    ja++;
                    mo=0;
                }

                if(mo >= 3 || ja >= 3){
                    pass = false;
                    break;
                }

                
                if(i>=1 && s[i] == s[i-1]){
                    if(s[i] == 'e' || s[i] == 'o'){
                        continue;   
                    }
                    else{
                        pass = false;
                        break;
                    }
                }

            }

            if(pass){
                cout << "<" << s << ">" << " is acceptable." << endl;
            }
        }


        if(!pass) cout << "<" << s << ">" << " is not acceptable." << endl;
        
    }

}