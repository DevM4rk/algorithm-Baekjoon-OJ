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

int T,F;
int parent[200001];
int friend_num[200001];

int find(int x){
    if(parent[x] == x) return x;

    int p = find(parent[x]); 
    parent[x] = p;      //부모?루트? 노드 갱신
    return p;
}

void merge(int x, int y){
    x = find(x);
    y = find(y);

    if(x != y) {
        parent[y] = x;
        friend_num[x] += friend_num[y];
    }

    cout << friend_num[x] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--){
        cin >> F;
        
        int cnt=1;
        map<string,int> m;
        for(int i=0; i<=F*2; i++){
            parent[i]= i;
			friend_num[i] = 1;
        }

        while(F--){
            string a,b;
            cin >> a >> b;
            
            if(m.find(a)==m.end()){
                m[a]=cnt;
                cnt++;
            }
            
            if(m.find(b)==m.end()){
                m[b]=cnt;
                cnt++;
            }

            merge(m[a],m[b]);
        }
    }
}//4195