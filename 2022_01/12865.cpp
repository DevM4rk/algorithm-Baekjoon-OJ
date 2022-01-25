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

int n,k;
int w[101], v[101];
int d[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(w[i] > j) d[i][j] = d[i-1][j];   // i번째 무게보다 가방이 버틸수있는 무게가 더 작다면 넣을 수 없음, 이 전의 값 유지
            else d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);       //버틸수있는무게가 같거나 크면 넣을 수 있음
                                                // 넣지 않았을때와 넣었을 때, 둘 중 더 큰 것으로 초기화
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=k; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d[n][k];
}
/*
냅색 문제는 i번째 물건을 넣었을 때와 넣지 않았을 때, 둘 중 더 가치가 큰 것을 가져오면 되는 것
D[A][B] = C : A번째 물건까지 왔고, 가방의 무게가 B일 때 가방에 담긴 물건들의 가치는 C

4 7
6 13
4 8
3 6
5 12

0 0 0 0 0 13 13 
0 0 0 8 8 13 13
0 0 6 8 8 13 14
0 0 6 8 12 13 14
*/