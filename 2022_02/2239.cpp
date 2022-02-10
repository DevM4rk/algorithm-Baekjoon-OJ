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

int arr[9][9];
bool a[9][10];    //가로
bool b[9][10];    //세로
bool c[9][10];    //블록

void dfs(int cnt){
    if(cnt==81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        exit(0);
    }

    int x = cnt/9;
    int y = cnt%9;

    if(!arr[x][y]){
        for(int i=1; i<=9; i++){
            if(a[x][i] || b[y][i] || c[(x/3)*3 + y/3][i]) continue;
            arr[x][y] = i;
            a[x][i] = true;
            b[y][i] = true;
            c[(x/3)*3 + y/3][i] = true;
           
            dfs(cnt+1);

            arr[x][y] = 0;
            a[x][i] = false;
            b[y][i] = false;
            c[(x/3)*3 + y/3][i] = false;
            
        }
    }
    else{
        dfs(cnt+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<9; i++){
        string s; cin >> s;
        for(int j=0; j<9; j++){
            arr[i][j] = s[j] - '0';
            if(arr[i][j]){  // 0이 아니면
                a[i][arr[i][j]] = true;
                b[j][arr[i][j]] = true;
                c[(i/3)*3 + j/3][arr[i][j]] = true;
            }
        }
    }

    dfs(0);
}