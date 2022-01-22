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

int n, ans1 = 1e9+1, ans2 = 1e9+1;
int arr[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int s = 0;
    int e = n-1;
    
    while(s < e){
        if(abs(arr[s]+arr[e]) < abs(ans1+ans2)){
            ans1 = arr[s];
            ans2 = arr[e];
        }

        //cout << s << " " << e << " " << endl;
        
        if(abs(arr[s+1]+arr[e]) < abs(arr[s]+arr[e-1])){
            s++;
        }
        else{
            e--;
        }
    }

    cout << ans1 << " " << ans2;
}