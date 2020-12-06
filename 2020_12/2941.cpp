#include <iostream>

using namespace std;

string str;

void find_str(string temp){
    int check=0;
    while(true){
        if( (check=str.find(temp, check)) != string::npos ){
            str.replace(check, temp.size(), "1");
        }
        else{
            break;
        }
    }
}

int solve(){
    find_str("c=");
    find_str("c-");
    find_str("dz=");
    find_str("d-");
    find_str("lj");
    find_str("nj");
    find_str("s=");
    find_str("z=");

    return str.size();
}

int main(){

    cin >> str;

    cout << solve() << endl;
}