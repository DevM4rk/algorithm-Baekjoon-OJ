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

    int n,k; cin >> n >> k;
    deque<pii> belt;    //내구도, 로봇유무
    for(int i=0; i<n*2; i++){
        int a; cin >> a;
        belt.push_back({a,0});
    }

    int ans=0,cnt=0;
    while(true){
        ans++;
        //1
        auto node = belt.back(); belt.pop_back();
        belt.push_front(node);

        //2
        if(belt[n-1].second){    //N에 도착한 벨트에 로봇이 있을 경우 내림
            belt[n-1].second--;
        }
        for(int i=n-2; i>=0; i--){
            if(belt[i].second && belt[i+1].first && !belt[i+1].second){ 
                belt[i].second--;   
                belt[i+1].first--;
                belt[i+1].second++;
                if(belt[i+1].first == 0) cnt++;
            }
        }

        if(belt[n-1].second){    //N에 도착한 벨트에 로봇이 있을 경우 내림
            belt[n-1].second--;
        }

        //3
        if(belt[0].first){
            belt[0].first--;
            belt[0].second++;
            if(belt[0].first == 0) cnt++;
        }
        
        //4
        if(cnt>=k) break;
    }
    cout << ans;
}
//8:47 ~ 9:10