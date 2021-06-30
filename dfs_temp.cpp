#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, x, y, arr[100001];
vi v[100001];
bool visited[100001];

void DFS(int n){
    visited[n]=true;

    for(int i=0; i<v[n].size(); i++){
        if( visited[v[n][i]] == true ) continue;
        arr[v[n][i]] = n;
        DFS(v[n][i]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    for(int i=0; i<N-1; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    DFS(1);

    for(int i=2; i<=N; i++)
        cout << arr[i] << endl;
}
// 11725