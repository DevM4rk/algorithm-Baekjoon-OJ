#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define INF 987654321

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

int N,S;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;

    int a[N];
    for(auto &i : a) cin >> i;

    int s=0, e=0, sum=a[0], ans=INF;

    while(s <= e && e < N){
        if(sum >= S){
            ans = min(ans, e-s+1);
            sum -= a[s];
            s++;
        }
        else{
            e++;
            sum += a[e]; 
        }
    }

    if(ans == INF) cout << 0;
    else cout << ans;
}//1806