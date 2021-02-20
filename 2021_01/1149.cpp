#include <iostream>
#include <vector>
#include <cmath>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N,r,g,b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    int house[N][2];
    
    house[0][0] = 0;
    house[0][1] = 0;
    house[0][2] = 0;

    for(int i=1; i<=N; i++){
        cin >> r >> g >> b;
        
        house[i][0] = min(house[i-1][1],house[i-1][2]) + r;
        house[i][1] = min(house[i-1][0],house[i-1][2]) + g;
        house[i][2] = min(house[i-1][0],house[i-1][1]) + b;
    }

    cout << min(house[N][0],min(house[N][1],house[N][2]));
}