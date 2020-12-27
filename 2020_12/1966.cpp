#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

queue<int>q;
queue<int>q2;

int t,N,M,temp,cnt=0,arr[101]={0,}, first, import;

void solve(){
    for(int i=100; i>=0; i--){
        if(arr[i]!=0){
            first = i;

            while( q.front() != first ){
                temp = q.front();
                q.pop();
                q.push(temp);

                temp = q2.front();
                q2.pop();
                if( temp == 1) q2.push(1);
                else q2.push(0);
            }

            q.pop();
            cnt++;

            if(q2.front() == 1) break;
            q2.pop();

            arr[i]--;
            i++;
        }
    }
}

int main(){
    cin >> t;
    
    while(t--){
        cin >> N >> M;
         
        for(int i=0; i<N; i++){
            cin >> temp;
            q.push(temp);
            arr[temp]++;
            if( M==0 ) {
                q2.push(1);
                M--;
            }
            else {
                q2.push(0);
                M--;
            }
        }

        solve();

        cout << cnt << endl;
        
        //reset
        q = queue<int>();
        q2 = queue<int>();
        memset(arr, 0, 100);
        cnt=0;
    }
}