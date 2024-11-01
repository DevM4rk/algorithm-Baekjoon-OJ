#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,ans=0; cin >> n;
    for(int i=0; i<n; i++){
        vector<int> ap;
        string s; cin >> s;

        char bef='A';
        bool b=true;
        ap = vector<int> (26);
        for(auto c : s){
            int x = c-'a';

            if(ap[x] > 0 && bef != c) b=false;
            ap[x]++;
            bef = c;
        }
    
        if(b){
            ans++;
        }
    }
    cout << ans;
}