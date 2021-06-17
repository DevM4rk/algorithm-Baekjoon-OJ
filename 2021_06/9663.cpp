#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, cnt=0;
int visited[16][16] = {0,};

void visit_check(int state, int line, int i){
            
            //근데 이렇게 true 해놓고 false로 바꾸면 이미 true로 바꿔놓은 애들도 false가 되어버림 문제해결해야댐
            for(int a=0; a<N; a++){
                visited[line][a] += state;
                visited[a][i] += state;

                if( line+a < N && i+a < N )             
                    visited[line+a][i+a] += state;

                if( line+a < N && i-a >= 0 ) 
                    visited[line+a][i-a] += state;
                    
                if( line-a >= 0 && i+a < N ) 
                    visited[line-a][i+a] += state;

                if( line-a >= 0 && i-a >= 0 ) 
                    visited[line-a][i-a] += state;

            }
                // visited[line][i] 가 6번 중복되므로 5만큼 빼주기
                visited[line][i] -= state*5;

}

void solve(int line){

//  line == N 일때 cnt++ 하고 리턴
    if( line == N ){
        cnt++;
        return;
    }

    for(int i=0; i<N; i++){
        if( visited[line][i] == 0 ){

            // 상하좌우대각선 true로 만들고 다음라인으로 넘어가기위해 line+1해서 재귀
            visit_check(1, line, i);

            solve(line+1);

            // 다시 false로 만듦
            visit_check(-1, line, i);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    solve(0);

    cout << cnt;
}