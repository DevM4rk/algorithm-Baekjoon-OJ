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

int N, ans_s,ans_e;
int target = 2000000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    int a[N];
    for(auto &i : a) cin >> i;

    sort(a, a+N);

    int s = 0;
    int e = N-1;
    
    while(s < e){
        int sum = a[s]+a[e];
        
        if(abs(sum) < target){
            target = abs(sum);
            ans_s = s;
            ans_e = e;
        }

        if(sum < 0) 
            s++;
        else 
            e--;
    }

    cout << a[ans_s] << " " << a[ans_e];
}