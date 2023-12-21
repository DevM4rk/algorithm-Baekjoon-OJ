#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> lamp;
    for(int i=0; i<m; i++){
        int x; cin >> x;
        lamp.push_back(x);
    }

    int st=0, end=n, mid=0;
    while( st < end){
        mid = (st + end) /2;
        // cout << st << " " << end << " " << mid << " ";
        bool check=true;

        if(lamp[0] - mid > 0 || lamp[m-1] + mid < n){
            check=false;
        }

        for(int i=0; i<m-1; i++){
            if(lamp[i]+mid < lamp[i+1]-mid ){ 
                check = false;
                break;
            }
        }

        // cout << check << endl;
        if(check){
            end = mid;
        }
        else{
            st = mid+1;
        }
    }
    cout << st;
}