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

int k;
int S[13], ans[6];
bool vis[13];

void btk(int cnt, int idx){
    if(cnt == 6){
        for(int i=0; i<6; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<k; i++){
        if(vis[i]) continue;
        ans[cnt] = S[i];
        vis[i] = true;
        btk(cnt+1, i);
        vis[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true){
        cin >> k;
        if(k == 0) break;
        

        for(int i=0; i<k; i++)
            cin >> S[i];
        
        btk(0, 0);
        cout << "\n";

        fill(S, S+13, 0);
        fill(vis, vis+13, 0);
    }
}