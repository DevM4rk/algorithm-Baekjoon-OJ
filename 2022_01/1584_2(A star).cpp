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
int d[501][501];    //디버깅용
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

struct node{
    int x,y,f,g;
    node(int x, int y, int f, int g){
        this->x = x;
        this->y = y;
        this->f = f;
        this->g = g;
    }
};

struct cmp{
    bool operator()(node &a, node &b){
        if(a.g==b.g) return a.f > b.f;
        return a.g > b.g;
    }
};

priority_queue<node, vector<node>, cmp> pq; //open 좌표정보를 담는 x,y값과 휴리스틱을 이용하는 평가함수 f,g 값 받아야함
map<pii, int> visitMap;   //close 이미왔다간 좌표정보를 담는 x,y값과 이동횟수 확인을 위한 g 값

void dijk(){
    pq.push(node(0,0,0,0));
    d[0][0] = 0;

    int cnt = 0;    //디버깅용
    while(!pq.empty()){
        auto nod = pq.top(); pq.pop();
        int x = nod.x;
        int y = nod.y;
        int f = nod.f;
        int g = nod.g;
        
        cnt++;

        // for(int i=0; i<=MAX; i++){
        //     for( int j=0; j<=MAX; j++){
        //         cout << d[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << x << " " << y << " " << f << " " << g << endl;


        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>MAX || ny<0 || ny>MAX) continue;
            if(a[nx][ny] == 2) continue;
            if(d[nx][ny] != MAX*MAX) continue;
            
            int fn,gn,hn;
            gn = g;
            if(a[nx][ny] == 1) gn++;
            hn = MAX-nx + MAX-ny;
            fn = gn + hn;
            
            pq.push(node(nx,ny,fn,gn));
            d[nx][ny] = gn;
        }

        if (d[MAX][MAX] != MAX*MAX){
            cout << "cnt :" << cnt << endl;
            return;
        }
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

//6
1
6 0 0 6
1
0 0 0 0

2
0 0 3 3
3 3 6 6
2
0 4 2 6
4 0 6 2

2
0 0 3 3
3 3 6 6
2
0 3 3 6
3 0 6 3

1
1 3 1 3
2
0 1 5 1
2 3 6 3

1
1 3 1 3
2
0 1 499 1
2 3 500 3
*/