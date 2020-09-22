#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[9] = {0,};
bool check[9] = {0,};

void dfs(int cnt){
    if(cnt== M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1; i<=N; i++){
        if(check[i]!=true){
            check[i] = true;
            arr[cnt] = i ;
            dfs(cnt+1);
            check[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;

    dfs(0);
}