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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,x; cin >> n >> x;
    vi v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    
    int sum=0;
    for(int i=0; i<x; i++){
        sum += v[i];
    }
    int st=0, end=x-1, top=0, cnt=0;
    while(end<n){
        if(top < sum){
            top = sum;
            cnt=1;
        }
        else if( top == sum){
            cnt++;
        }

        sum -= v[st];

        st++;
        end++;

        sum += v[end];
    }

    if(top==0) cout << "SAD";
    else cout << top << endl << cnt;
    
}