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

vector<vector<int>> v(101);
vector<int> vv[101];
int n,m,r;

void debug(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

void rev(){
    vector<vi> tv;
    tv = v;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << tv[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> r;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int t; cin >> t;
            vv[i].push_back(t);
        }
    }

//    debug();

    rev();
}