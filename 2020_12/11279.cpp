#include <iostream>
#include <queue>

using namespace std;

int N,temp;
priority_queue<int> pq;

void solve(){
    if(temp != 0) pq.push(temp);
    else{
        if( pq.empty() ) cout << "0\n";
        else{
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    while(N--){
        cin >> temp;
        
        solve();
    }
    
}