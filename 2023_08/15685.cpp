#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v(101, vector<int>(101));

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int x,y,d,g;

void cal(int cnt){
    v[x][y] = 1;
    int nx = x + dx[d];
    int ny = y + dy[d];

}

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> y >> x >> d >> g;
        cal(0);
    }
}
/*
1

2
3 2
3 0 3 2

0

1
2 1
2 3 2 1


3

0
1 0                             - 1
1 2 1 0                         - 2
1 2 3 2 1 2 1 0                 - 3
1 2 3 2 3 0 3 2 1 2 3 2 1 2 1 0 - 4

[0 1 2 1 2 3 2 1]
3을 뒤집어서 +1하면
4의 앞 8개가 나옴
이걸 반복
*/