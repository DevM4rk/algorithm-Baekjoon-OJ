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

string board[5];
int ans;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void BFS(int sc, int yc){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<5; i++)
        cin >> board[i];
    
    BFS(0, 0);

    cout << ans;
}