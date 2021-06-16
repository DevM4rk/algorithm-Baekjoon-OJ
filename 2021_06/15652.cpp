#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M;
int arr[8] = {0,};
//bool visited[8] = {false,};

void solve(int cnt, int idx){

    if( cnt == M ){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=idx; i<=N; i++){
        
        //if( visited[i] == false ){
          //  visited[i] = true;
            arr[cnt] = i;
            solve(cnt + 1, i);
         //   visited[i] = false;
        //}
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    solve(0, 1);
}