#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> times) {
    ll ans = 0;
    
    ll s= 0;
    ll e= *max_element(times.begin(), times.end()) * ll(n); // llmax로 주면 답 x
    ll m;
    
    while(s<e){
        m = (s+e) / 2;
        ll t=0;
        for(int i=0; i<times.size(); i++)
            t+=m/times[i];
        cout << s << " " << e << " " << m << " " << t << endl;
        if(t<n){
            s=m+1;
        }
        else{
            e=m;
        }
    }

    return s;
}