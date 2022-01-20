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

int k, S[13], ans[13];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(true){
        cin >> k;
        if(k == 0) break;

        for(int i=0; i<k; i++)
            cin >> S[i];

        for(int i=6; i<k; i++)
            ans[i] = 1;         //뽑히지 않아야 할 원소를 표시

        do{
            for(int i=0; i<k; i++){
                if(!ans[i]) cout << S[i] << " ";
            }
            cout << "\n";
        }while(next_permutation(ans, ans+k));   //다시 첫 수열로 돌아가기 때문에 초기화 필요없음

        cout << "\n";
    }
}