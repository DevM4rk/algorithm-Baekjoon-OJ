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

long long N, M;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    vi v(N);
    for(int i=0; i<N; i++) cin >> v[i];

    sort(all(v));

    long long start = 1;
    long long end = v[N-1];
    
    while(start <= end){
        long long mid = (start+end)/2;
        
        long long ans = 0;
        for(int i=0; i<N; i++){
            if(v[i] > mid)
                ans += v[i] - mid;
        }

        //cout << start << " " << mid << " " << end << " " << ans << endl;
        
        if( ans < M ){
            end = mid-1;
        }        
        else{
            start = mid+1;
        }
    }

    cout << end;
}