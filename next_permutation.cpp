
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
typedef vector<ll>  vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int main() {
    vector<vector<int>> dice;
    int answer = 1;
    for(;;answer++) {
        string s = to_string(answer);
        vi v(dice.size());
        iota(all(v),0);
        bool pass = false;

        do {
            bool chk = true;
            for(int i=0; i<s.size(); i++){
                if(find(all(dice[v[i]]), s[i] - '0') == dice[v[i]].end()){
                    chk = false;
                  break;  
                } 
            }

            if(chk){
                pass = true;
                break;
            }

        } while(next_permutation(all(v)));

        if(!pass){
            cout << answer;
            break;
        }
    }
} // {{0, 1, 5, 3, 9, 2}, {2, 1, 0, 4, 8, 7}, {6, 3, 4, 7, 6, 5}}