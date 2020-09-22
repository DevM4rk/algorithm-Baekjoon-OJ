#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    if(a.length() == b.length())
        return a<b;
    return a.size() < b.size();
}

int main(){
    int N;
    cin >> N;
    string str[N];
    for(int i=0; i<N;i++) cin >> str[i];

    sort(str,str+N);
    sort(str,str+N,cmp);

    for(int i=0; i<N; i++){
        if(str[i]==str[i-1])continue;
        cout << str[i] << "\n";
    }
    return 0;
}