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

int n,k,l,ans;
int board[101][101];
int turn[10001];

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int x,y; cin >> x >> y;
        board[x-1][y-1] = 1;
    }

    cin >> l;
    for(int i=0; i<l; i++){
        int t; char c;
        cin >> t >> c;
        if(c == 'D'){
            turn[t] = -1;    //¿À¸¥ÂÊ
        }
        else{
            turn[t] = 1;    //¿ÞÂÊ
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }

    deque<tp> dq;
    dq.push_back({0,0,0});

    while(1){
        ans++;
        auto [x,y,d] = dq.back();

        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n){
            cout << ans;
            return 0;
        }
        for(auto [a,b,_] : dq){
            if(nx == a && ny == b){
                cout << ans;
                return 0;
            }
        }

        if(turn[ans] != 0){
            d += turn[ans];
            if(d == -1) d = 3;
            else if(d == 4) d = 0; 
        }

        if(board[nx][ny])
            board[nx][ny] = 0;
        else
            dq.pop_front();
        
        dq.push_back({nx,ny,d});
    }
}