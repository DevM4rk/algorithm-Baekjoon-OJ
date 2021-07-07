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

int n,m, a,b;
int parent[201];

int find(int x){
    if(parent[x] < 0) return x;

    int p = find(parent[x]); 
    parent[x] = p;      //부모?루트? 노드 갱신
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

    for(int i=0; i<=n; i++) parent[i]= -1;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a;

            if(a){
                merge(i,j);
            }
        }
    }

    bool c = true;
    cin >> b;
    int temp = find(b);
    for(int i=1; i<m; i++){
        cin >> b;
        if(temp != find(b)){
            c = false;
            break;
        }       
    }

    if(c) cout << "YES";
    else cout << "NO";
}