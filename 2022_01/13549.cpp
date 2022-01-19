#include <bits/stdc++.h>

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

#define MAX 100001

int N, K;
int vis[MAX];        
priority_queue<pii, vpii, greater<pii>> q;

void BFS(int x, int y){
    
    q.push({0,x});
    vis[x] = 1;
    
    while(!q.empty()){

        auto cur = q.top(); q.pop();
        int cnt = cur.first;
        int now = cur.second;

        if( now == y ){
            cout << cnt << endl;
            break;
        }

        //1697번과는 다르게 순간이동이 0초임
        // *2가 먼저 안오면 안됨
        
        if( now*2 < MAX && !vis[now*2] ){
            q.push({cnt, now*2});
            vis[now*2] = 1;
        }
        if( now+1 < MAX && !vis[now+1] ){
            q.push({cnt+1, now+1});
            vis[now+1] = 1;
        }
        if( now-1 >= 0 && !vis[now-1] ){
            q.push({cnt+1, now-1});
            vis[now-1] = 1;
        }        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    
    BFS(N, K);
}