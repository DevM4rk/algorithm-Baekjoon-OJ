#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define MAX 32001

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

int N,M;
vi v[MAX];
vi degree(MAX);
queue<int> q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;
    
    while(M--){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }

    for(int i=1; i<=N; i++)
        if(degree[i] == 0)
            q.push(i);
            
    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int i=0; i<v[node].size(); i++){
            int x = v[node][i];
            
            degree[x]--;

            if(degree[x] == 0) q.push(x);
        }
    }
}