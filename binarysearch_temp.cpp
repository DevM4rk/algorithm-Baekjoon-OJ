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
int arr[100000];

void solve(){

    int start = 0;
    int end = N-1;
    int mid;

    while(start <= end){
        mid = (start+end)/2;
        if(target == arr[mid]){
            cout << "1" << endl;
            return;
        }
        else if( target < arr[mid] ){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    cout << "0" << endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++) cin >> arr[i];

    sort(arr,arr+N);

    cin >> M;
    while(M--){
        cin >> target;
        solve();
    }
}