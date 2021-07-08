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
int p[10001];
vector<pair<int, pii>> v;

int find(int x){
    if(p[x] == x) return x;

    int parent = find(p[x]);
    p[x] = parent;
    return parent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> V >> E;

    for(int i=1; i<=V; i++) p[i] = i;

    for(int i=0; i<E; i++){
        cin >> A >> B >> C;
        v.push_back({C,{A,B}});
    }
    
    sort(all(v));
    
    for(int i=0; i<E; i++){
        int weight = v[i].first;
        int s = v[i].second.first;
        int e = v[i].second.second;

        s = find(s);
        e = find(e);

        if(s == e) continue;

        p[s] = e;

        sum += weight;
        num++;

        if(num == V-1){
            cout << sum;
            break;
        }
    }
}//1197