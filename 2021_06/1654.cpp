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

int N, K, target;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K >> N;

    vi v(K);
    for(int i=0; i<K; i++) cin >> v[i];

    sort(all(v));

    long long start = 1;
    long long end = v[K-1];
    
    while(start <= end){
        long long mid = (start+end)/2;
        
        int cnt = 0;
        for(int i=0; i<K; i++){
            cnt += v[i] / mid;
        }

        //cout << start << " " << mid << " " << end << " " << cnt << endl;
        
        if( cnt < N )
            end = mid-1;
        else
            start = mid+1;
    }

    cout << end;
}