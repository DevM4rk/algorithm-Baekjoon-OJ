#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, cnt=0;
bool ischeck1[40]; // 세로
bool ischeck2[40]; // 우하향 대각선
bool ischeck3[40]; // 우상향 대각선

void solve(int line){

    if(line == N){
        cnt++;
        return;
    }

    for(int i = 0; i<N; i++){
        if(ischeck1[i] || ischeck2[i+line] || ischeck3[i-line+N-1]) continue;
        
        ischeck1[i] = 1;
        ischeck2[i+line] = 1;
        ischeck3[i-line+N-1] = 1;
        
        solve(line+1);
        
        ischeck1[i] = 0;
        ischeck2[i+line] = 0;
        ischeck3[i-line+N-1] = 0;
            
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    solve(0);

    cout << cnt;
}