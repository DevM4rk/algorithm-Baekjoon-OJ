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
int arr[9];
bool vis[9];

void DFS(int cnt){

    if(cnt == m){
        for(int i=0; i<m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        arr[cnt] = i;
        vis[i] = true;
        DFS(cnt+1);
        vis[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    DFS(0);   // cnt
}