#include <bits/stdc++.h>

using namespace std;

int n,t;
vector<int> v(101);

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    cin >> t;
    while(t--){
        int m,num; cin >> m >> num;
        if(m == 1){
            for(int i=1; num*i <=n; i++){
                if(v[num*i]) v[num*i] = 0;
                else v[num*i] = 1;
            }
        }
        else{
            if(v[num]) v[num] = 0;
            else v[num] = 1;
            
            for(int i=1; i<=n; i++){
                if(num-i <= 0 || num+i > n) break;

                if(v[num-i] == v[num+i]){
                    if(v[num-i]){
                        v[num-i] = 0;
                        v[num+i] = 0;
                    }
                    else{
                        v[num-i] = 1;
                        v[num+i] = 1;
                    }
                }
                else{
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n ;i++){
        if(i!=1 && i % 20 == 1) cout << endl;
        cout << v[i] << " ";
    }
}