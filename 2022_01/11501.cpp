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

int t,n;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        ll ans=0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        int max=arr[n-1];
        for(int i=n-2; i>=0; i--){
            if(arr[i] > max) max = arr[i];
            else ans += max - arr[i];
        }

        cout << ans << "\n";
    }
}