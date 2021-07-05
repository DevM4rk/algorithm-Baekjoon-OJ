//웬만해선 다익스트라가 속도가 더 빠르기때문에 가중치가 음수일 때만 사용
//하나의 정점에서 모든 정점의 최단경로

#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

#define MAX 501
#define INF 987654321

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int N,M,A,B,C;
ll d[501]; //음의사이클 발생 경우, 그 수치가 int형의 범위를 넘어서는 경우도 있기 때문
vector<pair<pii, int>> v;

void solve(){
    fill(d, d+N+1, INF);
    d[1] = 0;

    for(int i=1; i<=N; i++){    //벨만포드의 조건 중 N-1번까지 반복을 해봐야 음의 사이클인지 구분 할 수 있음
        for(int j=0; j<v.size(); j++){
            int From = v[j].first.first;
            int To = v[j].first.second;
            int Cost = v[j].second;

            if (d[From] == INF) continue;

            if (d[To] > d[From] + Cost){
                d[To] = d[From] + Cost;

                if(i==N){           // N번째 반복 했을때에도 변화가 생긴다면 음의 사이클이 생긴 것
                    cout << -1 << endl;
                    return;
                }
            }
        }
    }

    for(int i=2; i<=N; i++){
        if(d[i] == INF) cout << -1 << endl;
        else cout << d[i] << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    while(M--){
        cin >> A >> B >> C;
        v.push_back({{A,B},C});
    }

    solve();
}//11657