#include <iostream>

using namespace std;

int main(){
    int N, K, A[10], cnt=0;
    cin >> N >> K;

    for( int i=0; i<N; i++) cin >> A[i];

    for( int i=N-1; i>=0; i--){
        cnt += K / A[i];
        K %= A[i];
        if ( K == 0 ) break;
        }
    cout << cnt << endl;
}