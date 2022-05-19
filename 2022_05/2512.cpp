#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int arr[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int cnt=0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        cnt += arr[i];
    }
    int m; cin >> m;
    if(cnt <= m){
        cout << *max_element(arr, arr+n);
        return 0;
    }

    int st=0, end=m;
    while(st<end){
        int mid = (st + end)/2;
        int sum=0;
        for(int i=0; i<n; i++){
            if(arr[i] <= mid){
                sum += arr[i];
            }
            else{
                sum += mid;
            }
        }
        if( sum <= m ){
            st = mid+1;
        }
        else{
            end = mid;
        }
    }

    cout << st-1;
}
//1:00 ~ 1:10