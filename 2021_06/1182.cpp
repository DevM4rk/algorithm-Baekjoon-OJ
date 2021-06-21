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

int N, S, cnt=0;
int arr[20];
bool visited[20] = {false,};

void solve(int sum, int idx){

        //cout << sum << " " << idx << endl;
    if( sum == S && idx != 0 ){
        cnt++;
    }

    for(int i=idx; i<N; i++){
        solve(sum + arr[i], i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> S;

    for(int i=0; i<N; i++) cin >> arr[i];

    solve(0, 0);

    cout << cnt;
}