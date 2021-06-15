#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, l, x_start, y_start, x_target, y_target;

int x_knight[8]={-2, -2, -1, -1, 1, 1, 2, 2};
int y_knight[8]={-1, 1, -2, 2, -2, 2, -1, 1};


void bfs(){
    bool visited[300][300] = {false};
    
    queue<pair<pii, int>> q;
    q.push( {{x_start, y_start}, 0} );

    visited[x_start][y_start] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if ( x == x_target && y == y_target ){
            cout << cnt << endl;
            break;
        }
    
        for(int i=0; i<8; i++){
            int dx = x + x_knight[i];
            int dy = y + y_knight[i];
            
            if( dx < 0 || dy < 0 || dx >= l || dy >= l || visited[dx][dy] ) continue;

            visited[dx][dy] = true;
            q.push( {{dx, dy}, cnt+1} );
        } 
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    while(N--){
        cin >> l;
        
        int arr[l][l]={0};

        cin >> x_start >> y_start;
        cin >> x_target >> y_target;

        bfs();
    }
}