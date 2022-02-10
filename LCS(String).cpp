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

string s1,s2;
int dp[1005][1005]={};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s1 >> s2;

    for(int i=1; i<=s1.size(); i++){        // 한개씩 뽑아서 비교
        for(int j=1; j<=s2.size(); j++){    // 비교당할 문자열
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    // for(int i=1; i<=s1.size(); i++){
    //     for(int j=1; j<=s2.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[s1.size()][s2.size()];
}//9251
/*
ACAYKP   CAPCAK

\ 0 C A P C A K
0 0 0 0 0 0 0 0 
A 0 0 1 1 1 1 1
C 0 1 1 1 2 2 2
A 0 1 2 2 2 3 3
Y 0 1 2 2 2 3 3
K 0 1 2 2 2 3 4
P 0 1 2 3 3 3 4

*/