#include <iostream>
#include <algorithm>

using namespace std;

int N,M;
int arr[9] = {0,};
bool check[9] = {0,};

bool sortcheck(){
    for(int i=1; i<M; i++){ 
        if ( arr[i-1] > arr[i] ) return false;
    }
    return true;
}

void dfs(int cnt){
    if(cnt == M){
        if(sortcheck()){
            for(int i=0; i<M ; i++){
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        return ;
    }

    for(int i=1; i<=N; i++){
            arr[cnt] = i;
            dfs(cnt+1);
    }
}

int main(){
    cin >> N >> M;

    dfs(0);
}