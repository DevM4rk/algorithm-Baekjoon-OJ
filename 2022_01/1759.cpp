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

int L, C;
bool vis[16];
char S[16], ans[16];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void btk(int cnt, int idx){
    if(cnt == L){
        int chk1=0, chk2=0;
        for(int i=0; i<L; i++){
            if(aeiou(ans[i])) chk1++;
            else chk2++;
        }

        if(chk1 < 1 || chk2 < 2) return;  //최소 모음1개, 자음2개
        
        for(int i=0; i<L; i++){
            cout << ans[i];
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<C; i++){
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

    cin >> L >> C;

    for(int i=0; i<C; i++)
        cin >> S[i];

    sort(S, S+C);

    btk(0, 0);
}