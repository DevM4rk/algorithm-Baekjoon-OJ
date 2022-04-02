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

vector<vi> v(10, vi(10, 0));
int onecnt, ans=2e9, attcnt;
int paper[] = {0,5,5,5,5,5};

bool check(int x, int y, int n){
    for(int i=x; i<x+n; i++){
        for(int j=y; j<y+n; j++){
            if(i >= 10 || j >= 10) return false;
            if(!v[i][j]) return false;
        }
    }

    return true;
}

void attach(int x, int y, int n){
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            v[i][j]=0;

    onecnt -= n*n;
    attcnt++;
    paper[n]--;
}

void clean(int x, int y, int n){
    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            v[i][j]=1;

    onecnt += n*n;
    attcnt--;
    paper[n]++;
}

void dfs(int x, int y){

    if(onecnt==0){
        ans=min(ans, attcnt);
        return;
    }

    for(int i=x; i<10; i++){
        for(int j=y; j<10; j++){
            if(v[i][j]){
                for(int k=5; k>0; k--){
                    if(check(i,j,k) && paper[k]){
                        attach(i,j,k);
                        dfs(i,j);
                        clean(i,j,k);
                    }
                }
                return; // ������ ���ϰ� �Ѿ� �� ���, 1�� ���ΰ� �����Ÿ� ���°Ŷ� �Ȱ���
            }
        }
        y=0;    // ���ϸ� �����࿡���� y���� �Ⱦ 0~y�� ����
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> v[i][j];
            if(v[i][j]) onecnt++;
        }
    }

    dfs(0,0);
    
    if(ans==2e9) ans=-1;
    cout << ans;
}
//ó�� ������ ����

    // //n�� �Ű������� �ѱ�鼭 -1�� ��ư��� ���
    // //func(int x,int y, int n){ //ó���� 0,0,5
    //     if(onecnt==0){
    //         ans=min(~~~);
    //         return;
    //     }
    //     if(n==0){
    //         //�迭�� ��� 0�̸� ans=min(ans,cnt); return;;
    //         //1�� ������ return;
    //     }

    //     for(int i=x; i<10; i++){
    //         for(int j=y; j<10; j++){
    //             //if v[i][j] == 1, n*nũ�⸸ŭ 1�� �ִ��� Ȯ��
    //             //������ 0���� �ٲ�, n�ǻ����� ���� -1, cnt++ , onecnt -= n*n;
    //             //���� �����̰� �� �޾����� func(0,0,n-1)
    //             //func( i,j, n, �ٲ� �迭�� ������ ����)
    //             //�ٽ� ����
    //         }
    //     }
    //     //�� ������ func(0,0,n-1)