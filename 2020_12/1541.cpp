#include <iostream>

using namespace std;

int main(){
    int sum=0;
    bool plus=true;
    string str, temp = "";

    cin >> str;

    for(int i=0; i<=str.size(); i++){

        if( str[i] == '-' || str[i] == '+' || str[i] == '\0' ){

            if (plus) sum += stoi(temp);
            else sum -= stoi(temp);
            
            temp = "";
            if ( str[i] == '-') plus = false;
        }
        else{
            temp += str[i];
        }
    }    

    cout << sum << endl;
}

// - 가 나온 순간부터 그 뒤로 오는 수는 모두 빼면 됨