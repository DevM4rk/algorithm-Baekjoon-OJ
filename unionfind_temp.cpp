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

int n,m, c,a,b;
int parent[1000001];

int find(int x){
    if(parent[x] == x) return x;//루트노드 반환

    int p = find(parent[x]); 
    parent[x] = p;      //부모노드로 갱신
    return p;
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) parent[x] = y;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<=n; i++) parent[i]= i; 

    while(m--){
        cin >> c >> a >> b;

        if(c==0){
            merge(a,b);
        }
        else{ // x==1
            if(find(a) == find(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}//1717