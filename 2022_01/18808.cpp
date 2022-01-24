/*
회전 0 일 때
왼쪽위부터 0이면 스티커사이즈로 쟀을 때 틀 안넘어가면 계산해보기
계산하다가 1 겹치면 패스
안겹치면 스티커 붙이기
위 작업 모두 안되면 시계방향90도 회전 x 3
*/
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

int n,m,k;
int ans,cnt;          //ans 스티커 칸, cnt 스티커 붙인 수
int note[41][41];     //노트북 크기
int st[11][11];       //스티커 위치
int x,y;              //스티커 크기

void DebugNote(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << note[i][j] << " ";
        }
        cout << endl;
    }
}

void DebugSt(){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(){
    int t[11][11];
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            t[i][j] = st[i][j];

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            st[j][i] = t[x-1-i][j];

    swap(x,y);

    //DebugSt();
}

bool attach(int a, int b){
    
    //스티커 붙일 곳 있는지 확인
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(st[i][j] && note[a+i][b+j]) return false;    //붙일 곳에 이미 스티커 붙여져 있다면 끝
        }
    }

    //확인이 끝났으니 붙이기    
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            if(st[i][j])
                note[a+i][b+j] = 1;
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int idx=0; idx<k; idx++){
        int stcnt=0;    
        cin >> x >> y;

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                cin >> st[i][j];
                if(st[i][j]) stcnt++;        //스티커 크기, 1의 개수
            }
        }

        for(int r=0; r<4; r++){             //4회전
            bool paste = false;
            for(int i=0; i<=n-x; i++){       //스티커가 틀 안넘어가도록 x, y빼주기
                if(paste) break;
                for(int j=0; j<=m-y; j++){
                    if(attach(i,j)){
                        paste = true;
                        ans += stcnt;
                        break;
                    }
                }
            }
            //DebugNote();
            //cout << r << " " << paste << " " << ans << endl;

            if(paste) break;
            rotate();
        }
    }

    cout << ans;
}