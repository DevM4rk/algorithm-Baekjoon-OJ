#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,t; cin >> n >> t;

    vi limit(n);
    for(int i=0; i<n-1; ++i){
        int size; cin >> size;
        limit[i] = size;
    }
    limit[n-1] = INT_MAX; // 2e9
    
    vpii v[n];

    while(t--){
        char c; cin >> c;
        if(c == 'I'){
            int k,s; cin >> k >> s;
            
            for(int i=0; i<v[0].size(); i++){
                if(v[0][i].first == k){
                    v[0].erase(v[0].begin()+i);
                    break;
                }
            }
            v[0].push_back({k,s});

            
        }
        else{ // F
            int k; cin >> k;
            //cout 
        }
    }
}
/*
먼저 설계부터
insert 연산 시
레벨 1의 같은 키 있는지 확인 후 기존에 있던거 삭제, 새로운 메모리 할당
위 연산ㅇ ㅣ끝나고 난 후
메모리 제한을 넘기게 될 경우, avalanche 연산이 이루어 져야함


*/