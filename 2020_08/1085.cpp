#include <iostream>

using namespace std;

int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    x = min(min(w-x,h-y),min(x,y));
    cout << x; 
    return 0;
}