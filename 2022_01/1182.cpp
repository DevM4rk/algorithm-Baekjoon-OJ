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

int n,s, ans=0;
int arr[21];

void dfs(int sum, int cnt){
    if(sum == s && cnt != 0){
        ans++;
    }

    for(int i=cnt; i<n; i++){
        dfs(sum + arr[i], i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> s;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    dfs(0,0);

    cout << ans;
}