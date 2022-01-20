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

int func(int n, int r, int c){
    if(n==0) return 0;
    int half = (1<<n)/2;
    if(r < half && c < half) return func(n-1, r, c);                    //¿ÞÀ§
    if(r < half && c >= half) return half*half + func(n-1, r, c-half);  //¿ÀÀ§
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);//¿Þ¾Æ
    return 3*half*half + func(n-1, r-half, c-half);                     //¿À¾Æ
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,r,c;
    cin >> n >> r >> c;
    cout << func(n,r,c);
}