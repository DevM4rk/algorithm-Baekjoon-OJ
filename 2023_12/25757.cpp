#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; char c;
    cin >> n >> c;

    set<string> name;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        name.insert(s);
    }

    if(c == 'Y'){
        cout << name.size();
    }
    else if(c== 'F'){
        cout << name.size() / 2;
    }
    else{
        cout << name.size() / 3;
    }
}