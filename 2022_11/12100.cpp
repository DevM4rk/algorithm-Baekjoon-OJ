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

int n, ans;

void dfs(int cnt, vector<vi> board, vi v){
    //       1          3          1          4
    // if(v[0]==1 && v[1]==3 && v[2]==1 && v[3]==4 && v[4]==0){
    //     for(auto bo : board){
    //         for(auto b : bo){
    //             cout << b << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    if(cnt==5){
        for(auto b : board)
            ans = max(ans, *max_element(all(b)));
        return;
    }
    
    //좌
    vector<vi> cp_board = board;
    for(int i=0; i<n; i++){
        int st = 0;
        bool zero = false;

        for(int j=1; j<n; j++){
            int x = cp_board[i][j];
            if(x == 0){
                zero = true;
                continue;
            }

            if(cp_board[i][st] == 0){          //좌로 밀착
                zero = true;
                cp_board[i][j] = 0;
                cp_board[i][st] = x;
            }
            else{
                if(x == cp_board[i][st]){      //숫자가 같으면 합치기
                    cp_board[i][j] = 0;
                    cp_board[i][st] = x*2;
                    st++;
                }
                else{
                    st++;
                    if(zero){
                        cp_board[i][j] = 0;
                        cp_board[i][st] = x;
                    }
                }
            }
        }
    }
    v[cnt]=1;
    dfs(cnt+1, cp_board, v);
    v[cnt]=0;

    //우
    cp_board = board;
    for(int i=0; i<n; i++){
        int st = n-1;
        bool zero = false;

        for(int j=n-2; j>=0; j--){
            int x = cp_board[i][j];
            if(x == 0){
                zero = true;
                continue;
            }

            if(cp_board[i][st] == 0){      
                zero = true;    
                cp_board[i][j] = 0;
                cp_board[i][st] = x;
            }
            else{
                if(x == cp_board[i][st]){      //숫자가 같으면 합치기
                    cp_board[i][j] = 0;
                    cp_board[i][st] = x*2;
                    st--;
                }
                else{
                    st--;
                    if(zero){
                        cp_board[i][j] = 0;
                        cp_board[i][st] = x;
                    }
                }
            }
        }
    }
    v[cnt]=2;
    dfs(cnt+1, cp_board, v);
    v[cnt]=0;

    //상
    cp_board = board;
    for(int i=0; i<n; i++){
        int st = 0;
        bool zero = false;

        for(int j=1; j<n; j++){
            int x = cp_board[j][i];
            if(x == 0){
                zero = true;
                continue;
            }

            if(cp_board[st][i] == 0){    
                zero = true;      
                cp_board[j][i] = 0;
                cp_board[st][i] = x;
            }
            else{
                if(x == cp_board[st][i]){      //숫자가 같으면 합치기
                    cp_board[j][i] = 0;
                    cp_board[st][i] = x*2;
                    st++;
                }
                else{
                    st++;
                    if(zero){
                        cp_board[j][i] = 0;
                        cp_board[st][i] = x;
                    }
                }
            }
        }
    }
    v[cnt]=3;
    dfs(cnt+1, cp_board, v);
    v[cnt]=0;

    //하
    cp_board = board;
    for(int i=0; i<n; i++){
        int st = n-1;
        bool zero = false;

        for(int j=n-2; j>=0; j--){
            int x = cp_board[j][i];
            if(x == 0){
                zero = true;
                continue;
            }

            if(cp_board[st][i] == 0){    
                zero = true;      
                cp_board[j][i] = 0;
                cp_board[st][i] = x;
            }
            else{
                if(x == cp_board[st][i]){      //숫자가 같으면 합치기
                    cp_board[j][i] = 0;
                    cp_board[st][i] = x*2;
                    st--;
                }
                else{
                    st--;
                    if(zero){
                        cp_board[j][i] = 0;
                        cp_board[st][i] = x;
                    }
                }
            }
        }
    }
    v[cnt]=4;
    dfs(cnt+1, cp_board, v);
    v[cnt]=0;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    vector<vi> board(n, vi(n,0));
    vi v(5,0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    dfs(0, board, v);

    cout << ans;
}