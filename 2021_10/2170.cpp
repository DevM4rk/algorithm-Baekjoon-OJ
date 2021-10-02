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

    vector<pii> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, ans=0, s=-1000000001, e=-1000000001;
    cin >> N;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b ;
        v.push_back({a,b});
    }

    sort(all(v));

    for(const auto &[a, b] : v){
        if(e < a){
            ans += e-s;

            s=a;
        }
        if(e < b){
            e=b;
        }
        //cout << a << " " << b << endl;
        //cout << s << " " << e << endl;
    }
    ans += e-s;

    cout << ans ;
}