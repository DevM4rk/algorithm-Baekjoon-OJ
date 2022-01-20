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
char S[16];
int ans[16];

bool aeiou(char t){
  return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> C;

    for(int i=0; i<C; i++)
        cin >> S[i];
    sort(S, S+C);

    for(int i=L; i<C; i++)
        ans[i] = 1;

    do{
        int chk1=0, chk2=0;
        for(int i=0; i<C; i++){
            if(ans[i]) continue;
            if(aeiou(S[i])) chk1++;
            else chk2++;
        }

        if(chk1 >= 1 && chk2 >= 2){
            for(int i=0; i<C; i++){
                if(!ans[i]) cout << S[i];
            }
            cout << "\n";
        }
    }while(next_permutation(ans, ans+C));

}