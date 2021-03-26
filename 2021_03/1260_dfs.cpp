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

//TODO: stack ��ſ� vector�� �� �����ؼ� �Ѳ����� ����غ���
void dfs_stack(int x){
    vi s;
    s.push_back(x);
    visited[x] = true;
    cout << x << " ";

//������ �� ���̴��� �˾ƾ� �ҵ� ��
    while( !s.empty() ){
        int a = s.back();
        s.pop_back();

        for(int i=0; i<v[a].size(); i++){
            if( visited[v[a][i]] == false){

                // true üũ �ϰ� push �ϰ� while�� ���� break;
            }
            
        }

    }
    //2 3 4


}

void debug(){
    
    // v�� �� ����� ������ �����
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
        //��������� ���� �ִ� ���� : Ž���� ������ ��ȣ�� �־����� ������ �޹�ȣ���� ���� �� ���� �ִ� ��쿡 ���
        // ex) 1������ ���� ���ϰ� 2������ ������ ���
    }

    //���� �ϴ� ���� : ���� �� ���� �湮�ϱ� ����
    for(int i=1; i<=N; i++)
        sort(all(v[i]));

    //debug();
    
    //dfs_recursion(V);
    
    dfs_stack(V);
}