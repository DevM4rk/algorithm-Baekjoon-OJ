#include <iostream>

using namespace std;

void solve(int N, int start, int to, int finish){
    if ( N == 1) cout << start << " " << finish << endl;
    else{
        solve(N-1, start, finish, to);
        cout << start << " " << finish << endl;
        solve(N-1, to, start, finish);
    }
}

int main(){
    int N;
    cin >> N;
    cout << (1<<N)-1 << endl;
    solve(N, 1, 2, 3);
}
