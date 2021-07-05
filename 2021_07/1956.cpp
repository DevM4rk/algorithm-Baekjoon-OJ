#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 987654321
#define MAX 401 

int n, m;
int arr[MAX][MAX];
int from, to, weight, ans=INF;
 
void floyd_warshall() {
    for (int i = 1; i <= n; i++)             // i를 거치는 경우
        for (int j = 1; j <= n; j++)        
            for (int k = 1; k <= n; k++)    
                if (arr[j][i] != INF && arr[i][k] != INF)        
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
 
int main(){
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            arr[i][j] = INF;

    while(m--){
        cin >> from >> to >> weight;
        arr[from][to] = weight;
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if( i == j ) continue;
            ans = min(ans, arr[i][j] + arr[j][i]);
        }
    }
    if ( ans == INF) cout << -1;
    else cout << ans;
}