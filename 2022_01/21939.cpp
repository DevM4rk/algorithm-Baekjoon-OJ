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

int N,M,P,L;
map<int,int> m;
set<pii> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    while(N--){
        cin >> P >> L;  //P 문제, L 난이도
        m[P] = L;
        s.insert({L,P});
    }

    cin >> M;
    while(M--){
        string str; cin >> str;
        if(str == "add"){
            cin >> P >> L;
            m[P]=L;
            s.insert({L,P});
        }
        else if(str == "solved"){
            cin >> P;    
            int l = m[P];
            m.erase(P);
            auto it = s.find({l,P});
            s.erase(it);
        }
        else{   //recommend
            int x; cin >> x;
            if(x==-1){
                auto it = s.begin();
                cout << it->second << "\n";
            }
            else{
                auto it = prev(s.end());    //end는 끝 다음 값을 가르키기 때문에
                cout << it->second << "\n";
            }
        }
    }
}
/*
1 1000
2 1001
37 2667
55 2042
78 19998
*/