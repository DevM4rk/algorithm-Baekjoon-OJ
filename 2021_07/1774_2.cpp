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
double sum;
bool visited[1001];
vpii save;
double v[1001][1001];

void prim(){
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0,1});

    while(!pq.empty()){
        double weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(visited[node]) continue;
        
        visited[node] = true;

        sum += weight;

        for(int i=1; i <= n; i++){
            if(!visited[i])
                pq.push({v[node][i],i});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cout<<fixed;
    cout.precision(2);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        save.push_back({x,y});
    }

    for(int i=0; i<n; i++){
            double x1 = save[i].first;
            double y1 = save[i].second;
        
        for(int j=i+1; j<n; j++){
            double x2 = save[j].first;
            double y2 = save[j].second;

            double d = sqrt( pow( abs(x2-x1), 2 ) + pow( abs(y2-y1), 2 ) );
            v[i+1][j+1] = d;  //i -> j 가중치 d
            v[j+1][i+1] = d;  //i -> j 가중치 d
        }
    }

    while(m--){
        int a,b;
        cin >> a >> b;

        v[a][b] = 0;
        v[b][a] = 0;        
    }

    prim();

    cout << sum;
}