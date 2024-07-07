#include <bits/stdc++.h>

using namespace std;

int n, a[200], d[200];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    fill(d, d+n, 1);

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]) d[i] = max(d[i], d[j]+1);
        }
    }

    cout << n - *max_element(d,d+n);
}
/*
3 7 5 2 6 1 4
{10, 20, 10, 30, 20, 50

*/