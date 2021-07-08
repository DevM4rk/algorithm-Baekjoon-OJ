//간선의 가중치의 합이 최소여야 한다.
//n개의 정점을 가지는 그래프에 대해 반드시 (n-1)개의 간선만을 사용해야 한다.
//사이클이 포함되어서는 안된다.

/*크루스칼 
  가중치가 가장 작은 간선부터 시작하여 사이클이 생기지 않는 가중치가 그다음으로 작은 간선을
  추가 시키며 MST를 완성 하는 알고리즘 ElogE의 시간복잡도를 가진다.
  E의 수가 작다면 크루스칼 
  E의 수가 많다면 프림을 사용하는 것이 효율적임이 자명하다. 
*/
#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int V,E,A,B,C,sum,num;
int visited[10001];
vpii v[10001];

void prim(){
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0,1});
    int ans=0;

    while(!pq.empty()){
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        
        visited[node] = true;

        ans += weight;

        for(int i=0; i < v[node].size(); i++){
            if( !visited[v[node][i].second] )
                pq.push(v[node][i]);
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;

    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        v[A].push_back({C,B});
        v[B].push_back({C,A});
    }

    prim();

}//1197_2