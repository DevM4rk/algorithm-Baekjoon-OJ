//플로이드는 거쳐가는 정점을 기준으로 알고리즘을 수행
//모든 정점에서 모든 정점의 최단경로

#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 987654321
#define MAX 101 

int n, m;
int arr[MAX][MAX];
int from, to, weight;
 
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
        if (arr[from][to] > weight) 
            arr[from][to] = weight;
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ( i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}//11404