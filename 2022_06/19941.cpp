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
    
    int n,k; cin >> n >> k;
    string s; cin >> s;

    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i] == 'P'){
            for(int j=1; j<k+1; j++){
                if(i+j >= n) break;
                if(s[i+j] == 'H'){
                    cnt++;
                    s[i+j] = 'h';
                    s[i] = 'p';
                    break;
                }
            }
        }
        else if(s[i] == 'H'){
            for(int j=1; j<k+1; j++){
                if(i+j >= n) break;
                if(s[i+j] == 'P'){
                    cnt++;
                    s[i+j] = 'p';
                    s[i] = 'h';
                    break;
                }
            }
        }
    }

    cout << cnt;
}