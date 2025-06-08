#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q; cin >> q;

    while(q--){
        int a,b; cin >> a >> b;
        int in = abs(a-b);
        int out = 43-in;
        if( a > b) {
            swap(in,out);
        }
        // cout << in << out << endl;
        
        if(in < out){
            cout << "Inner circle line"<<endl;
        }
        else if( in > out){
            cout << "Outer circle line"<<endl;
        }
        else{
            cout << "Same" << endl;
        }

        // Inner circle line
        // Outer circle line
        // Same
    }

}