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

int n;
int p[100001];
vpii x,y,z;
vector<pair<int, pii>> dist;

int find(int x){
    if(p[x] == x) return x;

    int parent = find(p[x]);
    p[x] = parent;
    return parent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++){
        int ex,ey,ez;
        cin >> ex >> ey >> ez;
        x.push_back({ex,i});
        y.push_back({ey,i});
        z.push_back({ez,i});
    }

    sort(all(x));
    sort(all(y));
    sort(all(z));
    
    for(int i=1; i<n; i++){
        dist.push_back({ abs(x[i].first - x[i-1].first), { x[i].second , x[i-1].second }});
        dist.push_back({ abs(y[i].first - y[i-1].first), { y[i].second , y[i-1].second }});
        dist.push_back({ abs(z[i].first - z[i-1].first), { z[i].second , z[i-1].second }});
    }

    sort(all(dist));

    for(int i=0; i<=n; i++) p[i] = i;

    int sum=0;
    for(int i=0; i<dist.size(); i++){
        int d = dist[i].first;
        int a = dist[i].second.first;
        int b = dist[i].second.second;

        a = find(a);
        b = find(b);

        if(a == b) continue;

        p[a] = b;

        sum += d;
    }
    cout << sum;
}