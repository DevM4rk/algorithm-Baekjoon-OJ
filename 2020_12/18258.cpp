#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int>q;

void solve(){
    while(q.size() > 1){
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front() << endl;
}

int main(){
    cin >> N;
    for(int i=1; i<=N; i++) q.push(i);
    solve();
}