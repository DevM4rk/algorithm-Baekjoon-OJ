#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(int x, int y){
        if( abs(x) == abs(y) ){
            return x > y;    
        }
        else{
            return abs(x) > abs(y);
        }
    }
};

int N,temp;
priority_queue<int,vector<int>,cmp> pq;

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