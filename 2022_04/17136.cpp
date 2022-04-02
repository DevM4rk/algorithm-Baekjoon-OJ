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
                return; // 리턴을 안하고 넘어 갈 경우, 1을 냅두고 다음거를 보는거랑 똑같음
            }
        }
        y=0;    // 안하면 다음행에서도 y부터 훑어서 0~y를 못봄
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
//처음 생각한 로직

    // //n을 매개변수로 넘기면서 -1씩 깎아가며 재귀
    // //func(int x,int y, int n){ //처음엔 0,0,5
    //     if(onecnt==0){
    //         ans=min(~~~);
    //         return;
    //     }
    //     if(n==0){
    //         //배열이 모두 0이면 ans=min(ans,cnt); return;;
    //         //1이 있으면 return;
    //     }

    //     for(int i=x; i<10; i++){
    //         for(int j=y; j<10; j++){
    //             //if v[i][j] == 1, n*n크기만큼 1이 있는지 확인
    //             //있으면 0으로 바꿈, n의색종이 개수 -1, cnt++ , onecnt -= n*n;
    //             //만약 색종이가 다 달았으면 func(0,0,n-1)
    //             //func( i,j, n, 바뀐 배열과 색종이 개수)
    //             //다시 복귀
    //         }
    //     }
    //     //다 돌고나면 func(0,0,n-1)