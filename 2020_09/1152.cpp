#include <iostream>

using namespace std;

int main(){
    int cnt=1,temp=1;
    string N;
    getline(cin, N);
    if( N.back() == ' ') cnt=0;
    while(N.find(" ",temp)!=string::npos){
        temp = N.find(" ",temp)+1;
        cnt++;
    }
    std::cout << cnt;
    return 0;
}
//The Curious Case of Benjamin Button
// Mazatneunde Wae Teullyeoyo
//Teullinika Teullyeotzi 