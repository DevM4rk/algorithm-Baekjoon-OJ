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

int N, K, ans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;
    
    int start=1;
    int end=K;
    int mid;

    while(start <= end){
        mid = (start+end)/2;
        
        int cnt=0;
        for(int i=1; i<=N; i++)
            cnt += min(mid/i, N);
        
        cout << start << " " << mid << " " << end << " " << cnt << " " << ans << endl;

        if(cnt < K){
            start = mid + 1;
        }
        else{
            ans = mid;
            end = mid -1;
        }
    }
    cout << ans;
}
/* 
1 2 3
2 4 6
3 6 9

1 2 2 3 3 4 6 6 9
3*3 = 9개의 숫자중 7
*/