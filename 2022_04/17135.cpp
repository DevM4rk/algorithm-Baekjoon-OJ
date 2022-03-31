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
    int pos=n-1;  //�ڱ⺸�� ��ĭ ��, �����°� �������� ����
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

                if(cv[x][y] == 1){  // ���� ���� ã�� ���� ����, ����� �� ���� �޻�� �ݺ��ϱ� ������
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
//�������� �� ��ġ (r1, c1), (r2, c2)�� �Ÿ��� |r1-r2| + |c1-c2|�̴�.
//1�ϰ�� ���ο� 1�� ���� ��찡 ��
//�ü��� ��� ��ġ�� ��� 15*14*13 /3 /2 = 455����

    //3�� for�� �ü� ��ġ
    //�ü� �ϳ��� �ڱ⺸�� ��ĭ�� �������� d=1
    //d=2�̸� 1ĭ�� �»�� ���� (bfs)
    //���� �� �غ��� ��ġ�°� Ȯ���ϸ鼭 ����
    //��ĭ����
    //n�� �ݺ�?