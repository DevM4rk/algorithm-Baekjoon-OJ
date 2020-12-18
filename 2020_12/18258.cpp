#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int>q;

int solve(){
    if(q.size() == 1) cout << q.front() << endl;
    else{
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++) q.push(i);
    solve();
}