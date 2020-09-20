#include <iostream>

using namespace std;

int main(){
    int n, a[500][500]={0,},temp[100], sum=0, cnt=0, first=0;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
        cin >> a[i][i+1-j];
        }
        for(int j=i; j<2^j;j++){
            if(j==0) continue;

        }
    }

    printf("%d", sum);
    return 0;
}