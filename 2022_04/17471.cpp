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

int n,ans=2e9,sum1,sum2;
int num[11];
vi v[11];
bool vis[11];

void check(int k){
    sum2=0;
    int cnt=0;
    bool cvis[11];
    copy(vis, vis+n+1, cvis);

    for(int i=1; i<=n; i++){
        if(cvis[i]) continue;
        cnt++;
        sum2 += num[i];

        cvis[i] = true;
        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int x = q.front(); q.pop();

            for(auto nx : v[x]){
                if(cvis[nx]) continue;
                sum2 += num[nx];
                cvis[nx] = true;
                q.push(nx);
            }
        }
    }

    if(cnt != 1) return;
    
    // cout << k << " " << sum1 << " " << sum2 << endl;
    int temp = abs(sum1 - sum2);
    ans = min(ans, temp);
}

void dfs(int cnt, int k){
    if(cnt == k){

        //check 함수 복붙 및 cvis 부분 수정
        int cnt=0;
        bool cvis[11];
        copy(vis, vis+n+1, cvis);

        for(int i=1; i<=n; i++){
            if(!cvis[i]) continue;
            cnt++;
            if(cnt==2) return;

            cvis[i] = !true;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int x = q.front(); q.pop();

                for(auto nx : v[x]){
                    if(!cvis[nx]) continue;
                    cvis[nx] = !true;
                    q.push(nx);
                }
            }
        }

        check(k);
        
        return;
    }

    for(int i=cnt+1; i<=n; i++){
        if(vis[i]) continue;
        vis[i] = true;
        sum1 += num[i];
        
        dfs(cnt+1, k);
        vis[i] = false;
        sum1 -= num[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> num[i];
    
    for(int i=1; i<=n; i++){
        int t; cin >> t;
        while(t--){
            int a; cin >> a;
            v[i].push_back(a);
        }
    }
    
    for(int i=1; i<n; i++){
        dfs(0,i);
    }

    if(ans == 2e9) ans = -1;
    cout << ans;
}