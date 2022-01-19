#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

#define MAX 100001

int N, K;
int parent[MAX];
vector<int> check(MAX, 0);
queue<int> q;

void BFS(int x, int y){
    
    q.push(x);
    while(!q.empty()){

        int now = q.front();
        q.pop();

        if( now == y ){
            cout << check[now] << "\n";
            break;
        }

        for(auto nxt : {now+1, now-1, now*2}){
            if( nxt > 100000 || nxt < 0 ) continue;
            if( check[nxt] != 0) continue;
            q.push(nxt);
            check[nxt] = check[now]+1;
            parent[nxt] = now;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    
    BFS(N, K);

    deque<int> d;
    d.push_back(K);
    while(K != N){
        d.push_front(parent[K]);
        K = parent[K];
    }

    for(int p : d) cout << p << " ";  // µ¦ÀÇ ÀåÁ¡
}