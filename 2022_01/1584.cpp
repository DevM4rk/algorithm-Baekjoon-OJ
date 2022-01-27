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

const int MAX = 500;

int n;
int a[501][501];    //안전0, 위험1, 죽음2
int d[501][501];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dijk(){
    priority_queue<tp, vector<tp>, greater<tp>> pq;
    pq.push({0,0,0});
    d[0][0] = 0;

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int life,x,y;
        tie(life,x,y) = cur;
        
        if(d[x][y] != life) continue;

        // for(int i=0; i<=MAX; i++){
        //     for( int j=0; j<=MAX; j++){
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << life << " "<<x<<" "<<y<< endl;


        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>MAX || ny<0 || ny>MAX) continue;
            if(a[nx][ny] == 2) continue;

            int l = life;
            if(a[nx][ny] == 1) l++;

            if(d[nx][ny] > l){
                d[nx][ny] = l;
                pq.push({l, nx, ny});
            }
        }
        if (d[MAX][MAX] != MAX*MAX) return;
    }
}

void input(int num){
    for(int i=0; i<n; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1,x2);
        if(y1 > y2) swap(y1,y2);
        for(int j=x1; j<=x2; j++)
            for(int k=y1; k<=y2; k++)
                a[j][k] = num;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    input(1);
    cin >> n;
    input(2);

        // for(int i=0; i<=MAX; i++){
        //     for( int j=0; j<=MAX; j++){
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }

    for(int i=0; i<=MAX; i++)
        fill(d[i], d[i]+MAX+1, MAX*MAX);
    
    dijk();

    if(d[MAX][MAX] == MAX*MAX) cout << -1;
    else cout << d[MAX][MAX];
}
//10으로 테스트 해보기
/**
 * 
1
10 0 0 10
1
0 0 0 0

2
0 0 5 5
5 5 10 10
2
0 6 4 10
6 0 10 4

2
0 0 5 5
5 5 10 10
2
0 5 5 10
5 0 10 5

*/