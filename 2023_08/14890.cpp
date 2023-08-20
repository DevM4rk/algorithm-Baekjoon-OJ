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

int n,l;
int board[101][101];
int rv_board[101][101];
vector<vector<int>> vis(101, vector<int>(101,0));
int ans;

void cal(int bd[101][101]){
    
    for(int i=0; i<n; i++){
        int x;
        bool check=true;
        for(int r=0; r<n; r++){
            for(int t=0; t<n; t++){
                vis[r][t]=0;
            }
        }

        for(int j=0; j<n; j++){
            if(j==0){
                x = bd[i][j];
                continue;
            }

            if(x == bd[i][j]) continue;
            
            else if(abs(x-bd[i][j]) > 1) {
                check = false;
                break;
            }
            
            else if(x < bd[i][j]){
                if(j-l < 0){
                    check = false;
                    break;
                }

                for(int a=j-l; a<j; a++){
                    if(x != bd[i][a] || vis[i][a]){
                        check = false;
                        break;
                    }
                    vis[i][a] = 1;
                }
            }

            else{
                if(j+l > n){
                    check = false;
                    break;
                }

                x = bd[i][j];
                for(int a=j; a<j+l; a++){
                    if(x != bd[i][a]) {
                        check = false;
                        break;
                    }

                    vis[i][a] = 1;
                }
            }

            x = bd[i][j];
        }

        if(check){
            // cout << i << endl;
            ans++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> l;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rv_board[i][j] = board[j][i];
        }
    }

    cal(board);
    cal(rv_board);

    cout << ans;
    
}
/*
������ �Ѿ
1. ���ڰ� �ٸ��� ���̰� 1�̻��ϰ�� �Ұ���
2. ���� ���ٸ� (�������� ���Ŀ� ���� ��)
���� L����ŭ  x(y) >= 0 ���� Ȯ�ΰ� ���ڰ� ������ Ȯ�ΰ�  visitȮ��,üũ
3. ���� �������ٸ�
���� L��ŭ  x(y) < n ���� Ȯ�ΰ� visitüũ
*/