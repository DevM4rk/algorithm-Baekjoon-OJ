#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, sc, p; cin >> n >> sc >> p;

    int cnt=1;
    int same = 0;
    while(n--){
        int x; cin >> x;
        if(x >= sc) {
            cnt++;
            if(x == sc) same++;
            else same = 0;
        }
    }

    if(cnt > p) cout << -1;
    else cout << cnt-same;
}