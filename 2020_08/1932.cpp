#include <iostream>

using namespace std;

int main(){
    int n, a[500][500]={0,}, temp[500][500]={0,}, max_num=0;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
        cin >> a[i][i+1-j];
        }
    }
    temp[0][0] = a[0][0]; 

    for(int i=1; i<n; i++){
        temp[i][0] = a[i][0] + temp[i-1][0];
        temp[i][i] = a[i][i] + temp[i-1][i-1];
            for(int j=1; j<i; j++){
            temp[i][j] = max(a[i][j] + temp[i-1][j-1],a[i][j] + temp[i-1][j]);
        }        
    }
    for(int i=0; i < n ; i++){
        if ( max_num < temp[n-1][i] ) max_num = temp[n-1][i];
    }

    cout << max_num;
    return 0;
}