#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()
#define MAX 100000

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int n;
vi IDX(MAX), inorder(MAX), postorder(MAX);

void solve(int is, int ie, int ps, int pe){
    if(is > ie || ps > pe) return;
    
    int root = postorder[pe];
    cout << root << " ";
    
    int idx = IDX[postorder[pe]];
    int leftSize = idx-is;

    // 인오더 루트 기준 좌우로 나눠서 재귀 돌리기
    
    solve(is, idx-1, ps, ps+leftSize-1);//left
    solve(idx+1, ie, ps+leftSize, pe-1);//right
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> inorder[i];
        IDX[inorder[i]] = i; // root inx 찾기 위함
    }

    for(int i=0; i<n; i++) cin >> postorder[i];

    solve(0, n-1, 0, n-1);
}