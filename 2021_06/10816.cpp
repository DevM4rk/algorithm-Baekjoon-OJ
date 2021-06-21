#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M, target;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    vi v(N);

    for(int i=0; i<N; i++) cin >> v[i];

    sort(all(v));

    cin >> M;
    while(M--){
        cin >> target;
        auto l = lower_bound(all(v), target); // target이 나오는 첫번째 idx
        auto r = upper_bound(all(v), target); // target의 다음 idx
        cout << r - l << ' ';
    }
}