#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N;
int arr[11]={0,};
int op[4]; // + - * /

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    for(int i=0; i<4; i++)
        cin >> op[i];
    
    solve();
}