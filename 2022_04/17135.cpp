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

int n,m,d,ans;
vector<vi> v(15, vi(15, 0));

int dx[3] = {0,-1,0};
int dy[3] = {-1,0,1};

void SetArcher(int a1, int a2, int a3){
    vector<vi> cv = v;
    int kill=0;
    int pos=n-1;  //자기보다 한칸 앞, 때리는거 기준으로 설정
    int a[3] = {a1,a2,a3};
    // cout << a[0] << " " << a[1] << " " << a[2] << endl;

    while(pos>=0){

        set<pii> die;
        for(int i=0; i<3; i++){
            vector<vi> visit(15, vi(15,0));
            queue<tp> q;
            q.push({pos,a[i],1});
            visit[pos][a[i]] = 1;

            while(!q.empty()){
                int x,y,dist;
                tie(x,y,dist) = q.front(); 
                q.pop();

                if(cv[x][y] == 1){  // 제일 먼저 찾은 놈이 죽음, 가까운 순 다음 왼상우 반복하기 때문에
                    // cout << pos << " " << a[i] << " " << x << " " << y << endl;
                    die.insert({x,y});
                    break;
                }

                for(int j=0; j<3; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(visit[nx][ny] || dist >= d) continue;
                    visit[nx][ny] = 1;
                    q.push({nx,ny,dist+1});
                }
            }
        }

        for(auto &[x,y] : die){
            cv[x][y] = 0;
            kill++;
        }

        pos--;
    }
    // cout << kill << endl;
    ans = max(ans, kill);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> d;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> v[i][j];

    for(int i=0; i<m; i++)
        for(int j=i+1; j<m; j++)
            for(int k=j+1; k<m; k++)
                SetArcher(i,j,k);

    cout << ans;
}
//격자판의 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|이다.
//1일경우 세로에 1이 많은 경우가 답
//궁수가 모두 배치될 경우 15*14*13 /3 /2 = 455가지

    //3중 for문 궁수 배치
    //궁수 하나씩 자기보다 앞칸을 기준으로 d=1
    //d=2이면 1칸씩 좌상우 살핌 (bfs)
    //세명 다 해보고 겹치는거 확인하면서 죽임
    //한칸위로
    //n번 반복?