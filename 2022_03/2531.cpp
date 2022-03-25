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

    int n,d,k,c; cin >> n >> d >> k >> c;
    vi v(n);
    map<int,int> m;
    for(int i=0; i<n; i++){
        cin >> v[i];
        if(i < k){
            m[v[i]]++;
        }
    }
    
    int st = 0, end = k-1, ans=0;
    for(int i=0; i<n; i++){
        int cnt=m.size();
        if(!m.count(c)) cnt++;
        
        //for(auto [a,b] : m) cout << a << ":" << b << endl;
        //cout << st << " " << end << " " << cnt << endl;

        m[v[st]]--;
        if(m[v[st]]==0) m.erase(v[st]);

        st++;
        end++;
        if(end == n) end=0;
        m[v[end]]++;

        ans = max(ans, cnt);
    }
    cout << ans;
}