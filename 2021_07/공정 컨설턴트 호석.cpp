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

int N;
int X;
int arr[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> X ;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    int s = 1;
    int e = N;
    int ans = N;
    while(s < e){
        int m = (s+e)/2;
        priority_queue<ll, vl, greater<ll>> pq;

        for(int i=0; i<m; i++)
            pq.push(arr[i]);

        for(int i=m; i<N; i++){
            ll t = pq.top();
            pq.pop();
            pq.push(ll(t + arr[i]));
        }

        bool chk = false;
        for(int i=0; i<m; i++){
            ll t = pq.top();
            pq.pop();
            if( t > X) {
                chk = true;
                break;
            }
        }

        cout << s << " " << m << " " << e << " " << ans << endl;

        
        if (chk){
            s = m+1;
        }
        else{
            if(ans > m) ans = m;
            e = m;
        }

    }
    cout << e;
}
// 2 3 4 5 5 8
// 