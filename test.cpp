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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a[4] = {1,2,3,4};
    do{
        for(int i=0; i<4; i++)
            cout << a[i];
        cout << "\n";
    }while(next_permutation(a,a+4));

    /*3은 6개  , 4는 6*4 =24개  5!= 120 , 6! = 720
    123
    132
    213
    231
    312
    321
    */
}