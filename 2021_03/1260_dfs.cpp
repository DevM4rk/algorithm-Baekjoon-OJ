#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, M, V;
vi v[1001];
bool visited[1001];

void dfs_recursion(int x){
    visited[x] = true;
    cout << x << " ";

    for(int i=0; i<v[x].size(); i++)
        if( visited[v[x][i]]==false )
            dfs_recursion(v[x][i]);

}

//TODO: stack 대신에 vector로 값 저장해서 한꺼번에 출력해보기
void dfs_stack(int x){
    vi s;
    s.push_back(x);
    visited[x] = true;
    cout << x << " ";

//스택이 왜 쓰이는지 알아야 할듯 ㅠ
    while( !s.empty() ){
        int a = s.back();
        s.pop_back();

        for(int i=0; i<v[a].size(); i++){
            if( visited[v[a][i]] == false){

                // true 체크 하고 push 하고 while로 보냄 break;
            }
            
        }

    }
    //2 3 4


}

void debug(){
    
    // v에 값 제대로 들어가는지 디버깅
    for(int i=1; i<=N; i++){
        for(int j=0; j< v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}


int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> V;

    while(M--){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        //양방향으로 값을 넣는 이유 : 탐색을 시작할 번호가 주어지기 때문에 뒷번호부터 시작 할 수도 있는 경우에 대비
        // ex) 1번부터 시작 안하고 2번부터 시작할 경우
    }

    //정렬 하는 이유 : 작은 것 부터 방문하기 위해
    for(int i=1; i<=N; i++)
        sort(all(v[i]));

    //debug();
    
    //dfs_recursion(V);
    
    dfs_stack(V);
}