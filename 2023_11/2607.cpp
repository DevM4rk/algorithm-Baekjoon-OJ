#include <bits/stdc++.h>

using namespace std;
int arr[26];
int temp[26];
int ans=0;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    for(auto str : s){
        arr[str - 'A']++;
    }
    
    vector<int> v;

    for(int i=1; i<n; i++){
        cin >> s;
        for(auto str : s) {
            temp[str - 'A']++;
        }

        bool same = true;
        for(int j=0; j<26; j++){
            if(arr[j] != temp[j]){
                same = false;
                v.push_back(arr[j]-temp[j]);
            }

        }
        if(same){
            ans ++;
        }
        else if(v.size()==1 && abs(v[0])==1){
            ans++;
        }
        else if(v.size()==2 && abs(v[0])==1 && v[0] + v[1] == 0){
            ans ++ ;
        }

        fill(temp, temp+26, 0);
        v.clear();
    }

    cout << ans;
}