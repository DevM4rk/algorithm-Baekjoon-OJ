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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t,n,k,x,y,w;
    cin >> t;
    while(t--){
        cin >> n >> k;
        vi time(n+1, 0);
        for(int i=1; i<=n; i++) cin >> time[i];

        vi indeg(n+1, 0);
        vector<vi> v(n+1);
        for(int i=0; i<k; i++){
            cin >> x >> y;
            v[x].push_back(y);
            indeg[y]++;
        }

        cin >> w;
        vi sum = time;

        //위상정렬
        queue<int> q;
        for(int i=1; i<=n; i++)
            if(indeg[i]==0) q.push(i);

        while(!q.empty()){
            int now = q.front(); q.pop();
            //cout << now << " ";

            if(now == w) break;

            for(int i=0; i<v[now].size(); i++){
                int nx = v[now][i];
                indeg[nx]--;
                sum[nx] = max(sum[nx], sum[now]+time[nx]);

                if(indeg[nx]==0) q.push(nx);
            }
        }
        cout << sum[w] << endl;
    }
}