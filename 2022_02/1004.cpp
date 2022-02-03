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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int ans=0;
    int t,x1,y1,x2,y2,n,cx,cy,r;
    cin >> t;
    while(t--){
        int ans=0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;
        while(n--){
            cin >> cx >> cy >> r;
            int d1 = (x1-cx)*(x1-cx) + (y1-cy)*(y1-cy);
            int d2 = (x2-cx)*(x2-cx) + (y2-cy)*(y2-cy);
            int dr = r*r;
            //cout << d1 << " " << d2 << " " << dr << endl;

            if((d1<dr && d2>dr) || (d1>dr && d2<dr)) ans++;
        }
        cout << ans << endl;
    }
}
//두 점 중 한점을 포함하고 있으면 체크