#include <iostream>
#include <queue>

using namespace std;

int T,M,temp,cnt;
priority_queue<int,vector<int>,greater<int>> pq_min;
priority_queue<int> pq_max;

void solve(){
    if( pq_max.top() > temp ){
        pq_max.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 0 ){
            pq_min.push( pq_max.top() );
            pq_max.pop();
        }
    } 
    else{
        pq_min.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 1 ){
            pq_max.push( pq_min.top() );
            pq_min.pop();
        }
    }

    if(cnt%20==0) cout << "\n";
    if(cnt%2==0)cout << pq_max.top() << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    while(T--){
        cin >> M;

        cout << M/2+1 << "\n";

        //reset
        cnt = 1;    
        priority_queue<int> pq_empty;
        priority_queue<int,vector<int>,greater<int>> pq_empty2;
        pq_max = pq_empty;
        pq_min = pq_empty2;

        cin >> temp;
        pq_max.push(temp);
        cout << temp << " ";
            
        while(--M){
            cin >> temp;

            solve();
            cnt++;
        }

        cout << "\n";
    }
    
}