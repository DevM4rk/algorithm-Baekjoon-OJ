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

int N, ans_i,ans_s,ans_e;
ll target = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    ll a[N];
    for(auto &i : a) cin >> i;

    sort(a, a+N);

    for(int i=0; i<N; i++){
        int s = i+1;
        int e = N-1;
        
        while(s < e){
            ll sum = a[i]+a[s]+a[e];
            
            if(llabs(sum) < target){
                target = llabs(sum);
                ans_i = i;
                ans_s = s;
                ans_e = e;
            }

            if(sum < 0) 
                s++;
            else 
                e--;
        }
    }

    cout << a[ans_i] << " " << a[ans_s] << " " << a[ans_e];
}