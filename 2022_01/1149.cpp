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
int d[1001][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=0; j<3; j++)
            cin >> rgb[i][j];

    d[1][0] = rgb[1][0];
    d[1][1] = rgb[1][1];
    d[1][2] = rgb[1][2];

    for(int i=2; i<=n; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + rgb[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + rgb[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + rgb[i][2];
    }

    cout << min(d[n][0], min(d[n][1], d[n][2]));
    //*min_element(d[n],d[n]+3);
}
//d : °¢ »ö±òº°·Î Ä¥ÇÑ ÃÖ¼Ò°ª