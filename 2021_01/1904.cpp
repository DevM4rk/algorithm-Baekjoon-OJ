#include <iostream>

#define NUM 15746

using namespace std;

int N;

/*
1 1
2 2
3 3  100 001 111
4 5  1100 1001 0011 0000 1111
5 8   10000 00100 00001 11100 00111 10011 11001 11111
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    int fibo[N+1];

    fibo[1] = 1;
    fibo[2] = 2;

    for(int i=3; i<=N; i++) fibo[i] = (fibo[i-1] + fibo[i-2]) % NUM;

    cout << fibo[N];
}