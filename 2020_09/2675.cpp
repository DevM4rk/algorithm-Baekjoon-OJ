#include <iostream>

using namespace std;

int main(){
    int T,R;
    string S;
    cin >> T;

    while(T--){
        cin >> R >> S;
        for(int i=0; i<S.size();i++){
            for(int j=0; j<R; j++){
                cout << S[i];
            }
        }
        cout << endl;
    }
    return 0;
}