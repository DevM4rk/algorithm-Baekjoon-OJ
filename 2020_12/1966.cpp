#include <iostream>
#include <queue>

using namespace std;

queue<int>q;

int t,N,M,temp,cnt=0;

void solve(){

}

int main(){
    cin >> t;
    while(t--){
        cin >> N >> M;
        
        for(int i=0; i<N; i++){
            cin >> temp;
            q.push(temp);
        }

        solve();

        cout << cnt << endl;
        
        //reset
        q = queue<int>();
        cnt=0;
    }
}
/*
���� ������ �Ǿ����� ������ ������ �۾��ؾߵ�
*/