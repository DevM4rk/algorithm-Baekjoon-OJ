#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<vector<int>> v(11, vector<int> (11));
vector<vector<int>> food(11, vector<int> (11, 5));
vector<tuple<int,int,int>> tree;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main(){
    cin >> n >> m >> k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> v[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int x,y,z; cin >> x >> y >> z;
        tree.push_back({z,x,y});
    }

    sort(tree.begin(), tree.end());

    while(k--){
        for(int i=0; i<)
    }

}
/*
나무 정보를 담은 배열 vector tuple tree 나이가 맨앞에오도록 후 정렬

k동안 반복
1. tree 돌면서 양분 나눔
만약 부족하면 그 이후로 있는 나무들 양분으로 추가
2. 5의배수일때 번식
후 정렬
3. 양분 추가
*/