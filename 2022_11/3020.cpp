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

int bot[500002], top[500002];   //i번째 줄에 파괴해야하는 장애물 수
int minans, cntans;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,h; cin >> n >> h;
    for(int i=0; i<n/2; i++){
        int a,b; cin >> a >> b;
        bot[a]++;
        top[h+1-b]++;
    }

    for(int i=h-1; i>=1; i--)
        bot[i] += bot[i+1];
    
    for(int i=1; i<=h; i++)
        top[i] += top[i-1];
    
    for(int i=1; i<=h; i++)
        bot[i] += top[i];
    
    sort(bot, bot+h+1);

    // for(int i=1; i<=h; i++)
    //     cout << bot[i] << " ";
    // cout << endl;

    minans = *min_element(bot+1, bot+h+1);
    cntans = upper_bound(bot+1, bot+h+1, minans) - bot - 1;
    
    cout << minans << " " << cntans << endl;
}