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

    int n; cin >> n;

    priority_queue<int, vi, greater<int>> pq;
    for(int i=0; i<n*n; i++){
        int a; cin >> a;
        pq.push(a);
        if(pq.size() > n){
            pq.pop();
        }
    }

    cout << pq.top();
}
//8:47 ~ 9:06 메모리초과
//~9:24