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

int n,m;
vector<pair<int,pii>> v;
int p[100001];

int find(int x){
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c; cin >> a >> b >> c;
        v.push_back({c,{a,b}});
    }

    sort(all(v));
    iota(p, p+n+1, 0);

    int cnt=0,ans=0;
    for(int i=0; i<v.size(); i++){
        int cost = v[i].first;
        int st = v[i].second.first;
        int end = v[i].second.second;

        int x = find(st);
        int y = find(end);

        if(x==y) continue;

        p[x] = y;
        ans += cost;
        cnt++;

        if(cnt == n-1){
            ans -= cost;
            cout << ans;
            break;
        }
    }
}