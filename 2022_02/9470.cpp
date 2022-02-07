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

int t,k,m,p;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> k >> m >> p;

        vi v[m+1];
        vi indeg(m+1, 0);
        for(int i=0; i<p; i++){
            int a,b; cin >> a >> b;
            v[a].push_back(b);
            indeg[b]++;
        }

        multiset<int> cnt[m+1];
        queue<pii> q;   
        int ans=0;
        for(int i=1; i<=m; i++)
            if(indeg[i]==0) q.push({i,1});
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int x = cur.first;
            int cost = cur.second;

            if(x==m) ans = cost;
            //cout << x << " " << cost << endl;

            for(int nx : v[x]){
                cnt[nx].insert(cost);
                indeg[nx]--;
                if(indeg[nx]==0){
                    auto iter = cnt[nx].rbegin();
                    int cs=*iter;

                    if(cnt[nx].size()>=2){
                        auto iter2 = next(iter);
                        if(*iter == *iter2) cs = *iter +1;
                    }

                    q.push({nx, cs});
                }
            }
        }
        cout << k << " " << ans << endl;        
    }
}
//10:00~11:30