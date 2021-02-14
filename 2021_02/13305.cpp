#include <iostream>
#include <queue>

using namespace std;

int main()
{
    long long N ,temp, sum=0;
    cin >> N;

    long long dist[N-1], cost[N];
    for(int i=0; i<N-1; i++) cin >> dist[i];
    for(int i=0; i<N; i++) cin >> cost[i];

    temp = cost[0];

    for(int i=0; i<N-1; i++){ //check cost
        if( temp > cost[i] ) temp = cost[i];
        sum += temp * dist[i];
    }

    cout << sum;
}
