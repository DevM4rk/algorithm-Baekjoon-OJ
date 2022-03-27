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

int n,d;
vector<pii> v[10001];
int dist[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> d;

    for(int i=0; i<n; i++){
        int s,e,cost; cin >> s >> e >> cost;
        if(d < e || e-s <= cost) continue;
        v[s].push_back({cost,e});
    }

    fill(dist, dist+d+1, 2e9);
    dist[0]=0;

    for(int i=0; i<=d; i++){
        dist[i] = min(dist[i], dist[i-1]+1);

        for(auto road : v[i])
            if(dist[road.second] > dist[i] + road.first)
                dist[road.second] = dist[i] + road.first;
    }

    cout << dist[d];
}
//이 문제 좋네