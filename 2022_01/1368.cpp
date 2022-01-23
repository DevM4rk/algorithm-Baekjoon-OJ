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

int n,w,ans,cntE;
int p[302];
vector<tp> v;

int find(int x){
    if(x==p[x]) return x;
    return p[x] = find(p[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<=n; i++)
        p[i] = i;

    for(int i=1; i<=n; i++){
        cin >> w;
        v.push_back({w,i,0});   //0이라는 새로운 논과의 비용이라 생각
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> w;
            if(i>=j) continue;
            v.push_back({w,i,j});
        }
    }

    sort(all(v));

    for(int i=0; i<v.size(); i++){
        int cost,x,y;
        tie(cost, x, y) = v[i];

        x = find(x);
        y = find(y);

        if(x==y) continue;

        if(x < y) swap(x,y);
        p[y]=x;

        cntE++;
        ans += cost;

        if(cntE == n) break;
    }

    cout << ans;
}