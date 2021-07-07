//2개의 노드씩 이어나가면서 두 노드가 같은 그래프에 있는지 판단할 때
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

int n,m, cnt,a,b;
int parent[500001];
bool c;

int find(int x){
    if(parent[x] == x) return x;//루트노드 반환

    int p = find(parent[x]); 
    parent[x] = p;      //부모노드로 갱신
    return p;
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x == y) c=true;
    
    parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<=n; i++) parent[i]= i; 

    while(m--){
        cin >> a >> b;

        cnt++;
        merge(a,b);

        if(c) break;
    }
    
    if(c) cout << cnt;
    else cout << 0;
}