#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
priority_queue<int> pq;

int t,N,M,temp,cnt=0;

void solve(){

    while(!q.empty()){
        
            int a = q.front().first; 
            int b = q.front().second;
            q.pop();
        
        if( pq.top() == a ){
        
            pq.pop();
            cnt++;

            if(b == M) {
                cout << cnt << endl;
                break;
            }  

        }
        else{
            q.push({a,b});
        }
    }
}

int main(){
    cin >> t;
    
    while(t--){
        cin >> N >> M;
         
        for(int i=0; i<N; i++){
            cin >> temp;
            pq.push(temp);
            q.push({temp,i});
        }

        solve();
        
        //reset
        queue<pair<int,int>> empty;
        swap(q, empty);
        pq = priority_queue<int>();
        cnt=0;
    }
}