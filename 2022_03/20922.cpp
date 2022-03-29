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

int arr[200001];
int num[100001];
int ans,st;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,k; cin >> n >> k;

    for(int i=0; i<n; i++) cin >> arr[i];

    int cnt=0;
    for(int i=0; i<n; i++){
        num[arr[i]]++;
        cnt++;
        if(num[arr[i]] > k){
            while(num[arr[i]] > k){
                num[arr[st]]--;
                cnt--;
                st++;
            }
        }
        ans = max(ans, cnt);
    }

    cout << ans;
}