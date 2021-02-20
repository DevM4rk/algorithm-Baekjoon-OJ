#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M, V, t1, t2;
vi graph[1001];
bool visited[1001];

void dfs(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> V;
    
    while(M--){
        cin >> t1 >> t2;
        graph[t1].push_back(t2);
    }
    
    // graph에 값 제대로 들어가는지 디버깅
    for(int i=1; i<=N; i++){
        for(int j=0; j< graph[i].size(); j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    dfs();
}