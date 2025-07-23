#include <bits/stdc++.h>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int n,m,t;
vector<vector<int>> temp(50, vector<int>(50)), board(50, vector<int>(50));



int main(){
    cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }


}