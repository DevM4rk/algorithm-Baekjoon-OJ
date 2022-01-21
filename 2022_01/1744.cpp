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

int n,ans;
vi pv, nv;

void mul(vi &v){
    int a, b;
    while(v.size() >= 2){
        a = v.back(); v.pop_back();
        b = v.back(); v.pop_back();
        ans += a * b;
    }
    if(v.size()){
        ans += v[0];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;

    int a;
    for(int i=0; i<n; i++){
        cin >> a;
        if(a == 1) ans += 1;
        else if(a > 1) pv.push_back(a);
        else if(a <= 0) nv.push_back(a);
    }
    
    sort(all(pv));              // 3  6  9
    sort(all(nv), greater<>()); // 0 -3 -6

    mul(pv);
    mul(nv);

    cout << ans;
}
// ���� x ���� / ��� x ��� /
// ���� �ϳ��� ������ �� 0�̶� ���ع����� / 1�� �׳� ���ϱ�