#include <iostream>

using namespace std;

int result=1;

void solve(int N){
    if( N <= 1) return;
    result *= N;
    solve(N-1);
}

int main(){
    int N;
    cin >> N;
    solve(N);
    cout << result;
}