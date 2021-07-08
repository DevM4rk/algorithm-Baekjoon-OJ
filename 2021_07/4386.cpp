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
int p[101];
vector<pair<double,double>> v;
vector<pair<double, pair<double,double>>> dist;

int find(int x){
    if(p[x] == x) return x;

    int parent = find(p[x]);
    p[x] = parent;
    return parent;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout<<fixed;
    cout.precision(2);

    cin >> n;

    for(int i=0; i<n; i++){
        double x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }

    for(int i=0; i<n; i++){
            double x1 = v[i].first;
            double y1 = v[i].second;
        
        for(int j=i+1; j<n; j++){
            double x2 = v[j].first;
            double y2 = v[j].second;

            double d = sqrt( pow( abs(x2-x1), 2 ) + pow( abs(y2-y1), 2 ) );
            dist.push_back({d,{i,j}});  //i -> j 가중치 d
        }
    }

    sort(all(dist));

    for(int i=0; i<n; i++) p[i] = i;

    double sum=0;
    for(int i=0; i<dist.size(); i++){
        double d = dist[i].first;
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