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

int n;
int rgb[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            cin >> rgb[i][j];

    int ans=100000;
    for(int st=0; st<3; st++){  //1번집의 rgb 색 지정
        int d[1001][3];

        for(int i=0; i<3; i++){ //지정된 색 이외의 색은 MAX값을 줘서 선택되지 않도록 함
            if(st==i) d[1][i] = rgb[1][i];
            else d[1][i] = 100000;
        }

        for(int i=2; i<=n; i++){
            d[i][0] = min(d[i-1][1], d[i-1][2]) + rgb[i][0];
            d[i][1] = min(d[i-1][0], d[i-1][2]) + rgb[i][1];
            d[i][2] = min(d[i-1][0], d[i-1][1]) + rgb[i][2];
        }

        for(int i=0; i<3; i++){
            if(st==i) continue;
            ans = min(ans, d[n][i]);
        }
    }
 
    cout << ans;
}
/*
1. 1번집이 R이고 마지막집이 R일때 최소비용 x
2. 1번집이 R이고 마지막집이 G일때 최소비용
3. 1번집이 R이고 마지막집이 B일때 최소비용 

4. 1번집이 G이고 마지막집이 R일때 최소비용
5. 1번집이 G이고 마지막집이 G일때 최소비용 x
6. 1번집이 G이고 마지막집이 B일때 최소비용

7. 1번집이 B이고 마지막집이 R일때 최소비용
8. 1번집이 B이고 마지막집이 G일때 최소비용
9. 1번집이 B이고 마지막집이 B일때 최소비용 x
*/