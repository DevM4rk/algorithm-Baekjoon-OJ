#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n,m,k,ans=2e9;
vector<vi> arr(51, vi(51, 0));
int r[6],c[6],s[6];
bool vis[6];
vi order;

void rotation(int a){
    
    for(int i=0; i<s[a]; i++){
        int x1 = r[a]-s[a]+i, y1 = c[a]-s[a]+i, x2 = r[a]+s[a]-i, y2 = c[a]+s[a]-i;
        int temp = arr[x1][y1];

        for(int j=x1; j<x2; j++){
            arr[j][y1] = arr[j+1][y1];
        }
        for(int j=y1; j<y2; j++){
            arr[x2][j] = arr[x2][j+1];
        }
        for(int j=x2; j>x1; j--){
            arr[j][y2] = arr[j-1][y2];
        }
        for(int j=y2; j>y1; j--){
            arr[x1][j] = arr[x1][j-1];
        }
        arr[x1][y1+1] = temp;
    }
}

void play(){
    vector<vi> copyarr(51, vi(51, 0));
    copyarr = arr;

    for(int i=0; i<k; i++){
        rotation(order[i]);
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<=n; i++){
        int sum=0;
        for(int j=1; j<=m; j++){
            sum+=arr[i][j];
        }

        ans = min(ans, sum);
    }

    arr = copyarr;
}

void dfs(int cnt){
    if(cnt == k){
        play();
        return;
    }

    for(int i=0; i<k; i++){
        if(vis[i]) continue;
        vis[i] = true;
        order.push_back(i);
        dfs(cnt+1);
        vis[i] = false;
        order.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin >> r[i] >> c[i] >> s[i];
    }
    dfs(0);

    cout << ans;
}