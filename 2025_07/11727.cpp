#include <bits/stdc++.h>

using namespace std;

vector<int> v(1001);

int main(){
    int a; cin >> a;
    v[1] = 1;
    v[2] = 3;

    for(int i=3; i<= 1000; i++){
        v[i] = ( v[i-1] + v[i-2]*2 ) % 10007;
    }

    cout << v[a];

}
/*
*/ 