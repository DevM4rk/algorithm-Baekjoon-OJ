#include <iostream>

using namespace std;

int main(){
    string N;
    cin >> N;

    for(int i=0; i<= 'z'-'a'; i++){
        if( N.find('a'+i) == string::npos) cout << "-1 ";
        else cout << N.find('a'+i) << " ";
    }

    return 0;
}

/*
int main(){
    string N;
    cin >> N;
    int arr[26];
    memset(arr, -1, 26* sizeof(int));
    for(int i=0; i<N.length();i++){
        if (arr[N[i]-97] != -1) continue;
        arr[N[i]-97] = i;
    }

    for(int i=0; i<= 'z'-'a'; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
*/