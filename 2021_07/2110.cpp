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

int N, C;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> C;
    
    int a[N];
    for(auto &i : a) cin >> i;

    sort(a, a+N);


    int s = 0, e = a[N-1], res = 0;
    while(s <= e){

        int m = (s+e)/2;    // 두 공유기 사이의 최대 거리를 m으로 가정
        int pos=0, cnt=1;   // 공유기를 둔 위치, 둔 개수

        for(int i=1; i<N; i++){
            if( a[i] - a[pos] >= m ){   //간격이 m보다 클 경우
                cnt++;                  //공유기 개수 갱신
                pos = i;                //공유기 위치 갱신
            }
        }

        if(cnt >= C){               // 주어진 공유기와 개수가 같거나 그 이상일 경우
            if(res < m) res = m;    //cnt가 많아질수록 m은 작아지기때문에 res에 영향없음, cnt>C와 같이 둬도 되는 이유
            s = m+1;                
        }
        else{
            e = m-1;
        }
    }

    cout << res;
}