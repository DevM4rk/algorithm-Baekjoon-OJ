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

int m,n;
int arr[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> m >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int st = 0;
    int en = *max_element(arr, arr+n);
    int mid;

    while(st < en){
        mid = (st + en + 1)/2;
        
        ll cnt=0;
        for(int i=0; i<n; i++)
            cnt += arr[i] / mid;
        
        if(cnt >= m){
            st = mid;
        }
        else{
            en = mid-1;
        }
    }

    cout << st;
}