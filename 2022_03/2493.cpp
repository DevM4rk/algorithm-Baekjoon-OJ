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

    int n; cin >> n;
    stack<pii> s;
    for(int i=1; i<=n; ++i){
        int t; cin >> t;
        if(i==1){
            s.push({t,1});
            cout << 0 << " ";
            continue;
        }

        while(!s.empty()){
            //cout << s.top().first << " " << s.top().second << endl;
            if(s.top().first < t){
                s.pop();
            }
            else if(s.top().first > t){
                cout << s.top().second << " ";
                s.push({t,i});
                break;
            }
            else{
                cout << s.top().second << " ";
                break;
            }
        }

        if(s.empty()){
            cout << 0 << " ";
            s.push({t,i});
        }
    }
}