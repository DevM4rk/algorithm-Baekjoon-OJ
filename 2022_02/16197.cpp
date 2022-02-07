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

struct node{
    int x1,y1,x2,y2,cnt;
    node(int x1_, int y1_, int x2_, int y2_, int cnt_) : x1(x1_), y1(y1_), x2(x2_), y2(y2_), cnt(cnt_) {}
};

int n,m;
char arr[21][21];
queue<node> q;
map<pair<pii,pii>, int> visit;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int cal(int nx, int ny){
    if(nx < 0 || nx >= n || ny < 0 || ny >= m) //동전이 떨어짐
        return 0;                        
    else if(arr[nx][ny] == '#') // 제자리 반환
        return 1;                       
    else   // . or o 인 경우
        return 2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    vpii v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin >> c;
            arr[i][j] = c;
            if(c == 'o') v.push_back({i,j});
        }
    }

    q.push(node(v[0].first, v[0].second, v[1].first, v[1].second, 0));
    visit[{{v[0].first, v[0].second}, {v[1].first, v[1].second}}]++;

    bool b = false;
    int ans=-1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(b || cur.cnt==10 ) break;

        for(int i=0; i<4; i++){
            int nx1 = cur.x1 + dx[i];
            int ny1 = cur.y1 + dy[i];
            int nx2 = cur.x2 + dx[i];
            int ny2 = cur.y2 + dy[i];
            int one = cal(nx1,ny1);
            int two = cal(nx2,ny2);
            //cout << nx1 << " " << ny1 << " " << nx2 << " " << ny2 << " " << one << " " << two << endl;
            if((one == 0 && two == 0) || (one == 1 && two == 1)) continue;  // 두쪽 떨어지는 경우, 둘다 제자리인 경우 푸쉬 안함
            if(one == 0 || two == 0){   // 한쪽만 떨어지는 경우 성공!
                ans = cur.cnt+1;
                b = true;
                break;
            }
            
            if(one == 1){ // 한쪽만 제자리인 경우 제자리로 만들기
                nx1 = cur.x1;
                ny1 = cur.y1;
            }
            else if(two == 1){ 
                nx2 = cur.x2;
                ny2 = cur.y2;
            }
            if(nx1 == nx2 && ny1 == ny2) continue; //동전이 겹치는 경우 패스

            if(visit.count({{nx1,ny1},{nx2,ny2}})) continue; // 이미 지나왔던 것일 경우 패스

            //한쪽만 제자리이거나 양쪽 다 이동한 경우 푸쉬
            visit[{{nx1,ny1},{nx2,ny2}}]++;
            q.push(node(nx1,ny1,nx2,ny2,cur.cnt+1));
        }
    }

    cout << ans;
}
//8:00~9:30
/* 
00 x
01 o 
02 o
10 o
11 x
12 g
20 o
21 g
22 g
*/