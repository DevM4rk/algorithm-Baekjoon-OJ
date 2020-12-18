#include <iostream>

using namespace std;


void solve(int i, int j, int N){
    if( ((i/N)%3 == 1) && ((j/N)%3 == 1) ){
        cout << " ";
    } 
    else{
        if( N/3 == 0 )
            cout << "*";
        else
            solve(i,j,N/3);
    }
}

int main(){
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            solve(i,j,N);
        }
        cout << endl;
    }
}