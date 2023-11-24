#include <bits/stdc++.h>

using namespace std;

int main(){
    int h,w,n,m; cin>>h>>w>>n>>m;
    int x=1+n,y=1+m;
    int a=(h-1)/x+1,b=(w-1)/y+1;
    //cout<< x << y << a << b;
    cout << a*b;
}