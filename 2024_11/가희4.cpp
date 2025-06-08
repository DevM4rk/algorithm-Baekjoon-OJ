#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; getline(cin, s);
    auto idx = s.find('(');

    if(s.find('(') != string::npos){
        string name= s.substr(0, idx);
        string sub = s.substr(idx+1, s.size());
        sub.pop_back();

        cout<< name << endl << sub;
    }
    else{
        cout << s << endl << "-";

    }


}