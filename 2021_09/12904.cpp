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
 
    string S,T;
    cin >> S >> T;

    while(S.size() != T.size()){
        if(T.back() == 'A'){
            T.pop_back();
        }
        else{
            T.pop_back();
            reverse(all(T));
        }
    }

    if (S == T) cout << 1;
    else cout << 0;
}


/* 시간초과
string S, T;
int chk = 0;

void dfs(string s, int size){

    if(size==T.size()){
        if(s == T) chk = 1;
        return;
    }

    dfs(s+'A', size+1);

    reverse(all(s));
    dfs(s+'B', size+1);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> T;

    dfs(S,S.size());

    cout << chk;
}
//T의 길이까지 1 2를 dfs
*/ 