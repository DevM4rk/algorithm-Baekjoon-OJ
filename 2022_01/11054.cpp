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

int n,ans;
int a[1001];
int d[1001][2]; // 0은 계속 큰값 받는중, 1은 큰값 나온 후 작은값 나옴

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        fill(d[i], d[i]+2, 1);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] < a[i]) d[i][0] = max(d[i][0], d[j][0]+1);
            if(a[j] > a[i] && d[j][0] != 1) d[i][1] = max(d[i][1], d[j][0]+1); //꺾이는 순간
            if(a[j] > a[i]) d[i][1] = max(d[i][1], d[j][1]+1);
        }
    }
    
    for(int i=0; i<n; i++)
        ans = max(ans, *max_element(d[i], d[i]+2));

    cout << ans;    
}