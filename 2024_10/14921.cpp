#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int st=0, end=n-1, ans=INT_MAX;
    while(st<end){
        int mid = v[st] + v[end];
        if(abs(ans) > abs(mid)){
            ans = mid;
        }
        if(mid < 0){

            st++;
        }
        else{
            end--;
        }
    }
    cout << ans;
}