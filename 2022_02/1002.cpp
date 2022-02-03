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

    int t,x1,y1,r1,x2,y2,r2;
    cin >> t;
    while(t--){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        int a = pow(abs(x1-x2),2) + pow(abs(y1-y2),2);
        int in = pow(r1+r2,2);
        int out= pow(abs(r1-r2),2);
        //cout << a << " " << in << " " << out << endl;

        if(a==0){
            if(r1==r2) cout << -1 << endl;
            else cout << 0 << endl;
        }
        else{
            if(a==in || a==out) cout << 1 << endl;
            else if(a<in && a>out) cout << 2 << endl;
            else cout << 0 << endl;
        }
    }
}