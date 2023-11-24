#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int,tuple<int,int,int>> &a, const pair<int,tuple<int,int,int>> &b ){
    auto [o,t,th] = a.second;
    auto [oo,tt,tth] = b.second;

    if(o == oo){
        if(t == tt){
            return th > tth;
        }
        return t > tt;
    }
    return o > oo;
}

int main(){
    vector<pair<int,tuple<int,int,int>>> v;
    int n,k; cin >> n >> k;
    for(int i=1; i<=n; i++){
        int num,a,b,c; cin >> num >> a >> b >> c;
        v.push_back({num,{a,b,c}});
    }
    sort(v.begin(), v.end(), cmp);

    // for(auto a : v){
    //     cout << a.first << " ";
    // }

    int ans = -1;
    for(int i=0; i<n; i++){
        if(v[i].first == k){
            for(ans=i-1; ans>=0; ans--){
                if(v[i].second != v[ans].second) break;
            }
            break;
        }
    }
    cout << ans+2;

}