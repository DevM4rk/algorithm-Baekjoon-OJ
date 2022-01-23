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

int n,m;
int p[1000001];

int find(int x){
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    p[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for(int i=0; i<=n; i++){
        p[i] = i;
    }

    for(int i=0; i<m; i++){
        int x,a,b;
        cin >> x >> a >> b;
        for(int i=1; i<=n; i++) cout << p[i] << " ";
        cout << endl;
        if(x){  //Ãâ·Â
            a = find(a);
            b = find(b);
            if(a==b)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else{   //merge
            merge(a,b);
        }
    }
}