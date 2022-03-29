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

int N, K, cnt=0, t=2e9;
vector<int> check(MAX, 2e9);
bool visited[MAX];
queue<int> q;

void BFS(int x, int y){
    
    check[x]=0;
    q.push(x);

    while(!q.empty()){

        int now = q.front();
        q.pop();

        if( now == y && cnt==0){
            t = check[now];
            cout << t << endl;
        }

        if( t != 2e9 && now == y){
            cnt++;
        }

        for(auto nxt : {now+1, now-1, now*2}){
            if( nxt > 100000 || nxt < 0 ) continue;
            if( check[nxt] < check[now]+1 ) continue;
            q.push(nxt);
            check[nxt] = check[now]+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    
    BFS(N, K);
    
    cout << cnt;
}