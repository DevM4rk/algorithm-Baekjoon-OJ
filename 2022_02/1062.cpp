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

int n,k,ans; 
int visit[26];
unordered_set<char> s[51];

void dfs(int cnt, int idx){
    if(cnt == k-5){
        
        int sum=0;
        for(int i=0; i<n; i++){
            bool b=true;
            for(auto c : s[i]){
                if(!visit[c-'a']){   //0인게있다면 체크안함
                    b = false;
                    break;
                }
            }
            if(b) sum++;
        }
        ans = max(ans, sum);

        return;
    }

    for(int i=idx; i<26; i++){
        if(visit[i]) continue;
        visit[i] = 1;
        dfs(cnt+1, i+1);
        visit[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> k;

    for(int i=0; i<n; i++){
        string str; cin >> str;
        
        for(int j=4; j<str.size()-4; j++)
            s[i].insert(str[j]);
    }
    
    if(k<5){
        cout << 0;
        return 0;
    }

    visit['a'-'a']=1;
    visit['n'-'a']=1;
    visit['t'-'a']=1;
    visit['c'-'a']=1;
    visit['i'-'a']=1;

    dfs(0,0);

    cout << ans;
}
/*
a~z까지 visit으로 두고 백트래킹하기
antci 최소 5개 이상은 되어야 함
set 1
r
ehlo
r
---
set 3
b 
x 
d 
e 
f 
g 
h 
j 
k
*/