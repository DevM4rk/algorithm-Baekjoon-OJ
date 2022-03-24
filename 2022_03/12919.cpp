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

string S, T;

void dfs(string t){

    if(t.size() == S.size()){
        if(t == S){
            cout << 1;
            exit(0);
        }
        return;
    }

    if(t.back() == 'A'){
        string temp = t;
        temp.erase(temp.end()-1);
        dfs(temp);
    }
    if(t.front() == 'B'){
        string temp = t;
        reverse(all(temp));
        temp.erase(temp.end()-1);
        dfs(temp);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> S >> T;

    dfs(T);

    cout << 0;
}
// S -> T 의 경우 2^50의 시간복잡도
// T -> S 의 경우, 조건에 맞는 것만 dfs하여 시간 내로 가능