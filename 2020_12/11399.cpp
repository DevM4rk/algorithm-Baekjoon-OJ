#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, P[1000], result=0;
    cin >> N;

    for (int i=0; i<N; i++) cin >> P[i];

    sort(P,P+N);

    for (int i=0; i<N; i++) result += P[i]*(N-i);

    cout << result << endl;
}