//boj 11112���� ���� �����ؼ� ������
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

const string TARGET = "12345678#";

string s;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;

//f = g + h
//f ���ɼ�, ���� �������� ���� /  g ��������� ��, ������ Ƚ�� /  h ������ ����Ǵ� ��, ���ڸ��� ���� ���� ������ ��
struct node{
    string board;// ����� ���
    int g;       // g(n)
    int f;       // f(n)
    node(string board, int f, int g){
        this->board = board;
        this->f = f;
        this->g = g;
    }
};

struct cmp{
    bool operator()(node &a, node &b){
        if(a.f==b.f) return a.g > b.g;  // f�� ���ٸ� g�� ���� ��
        return a.f > b.f;               // f�� ���� ��
    }
};

priority_queue<node, vector<node> ,cmp> pq; // open, ���ɼ��� ���� ���ƺ��̴�(f���� ����) ������ ��� ����
unordered_map<string, int> visitMap;        // close, �̹� �ô� ����� �� ���� �ߺ� ����, value�� �̵�Ƚ��

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--){

        //�ʱ�ȭ
        visitMap.clear();
        while(!pq.empty()) pq.pop();
        s.clear();

        for(int i=0; i<3; i++){
            string temp;
            cin >> temp;
            s += temp;
        }

        pq.push(node(s,0,0));
        visitMap[s]=0;

        while(!pq.empty()){
            auto cnode = pq.top(); pq.pop();

            // ��� ���� ��� ����
            if(visitMap.count(TARGET)) break;

            int zero = cnode.board.find('#');
            int x = zero/3, y = zero%3;         // 0�� ��ġ�� 2���� �迭�� ǥ��

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
                
                string ns = cnode.board;
                swap(ns[x*3+y], ns[nx*3+ny]);   // 0�� �����¿� ��ġ ����
                if(visitMap.count(ns)) continue;// �̹� ������ ���̽��� �н�

                int f=0,g=0,h=0;
                for(int j=0; j<ns.size(); j++)  // �޸���ƽ ��(��ǥ��) ���ϱ�
                    if(ns[j] != TARGET[j]) h++; // ��ǥ ��尡 �Ǳ� ���� �ٸ� ��ġ�� �ִ� ���� üũ
                g = cnode.g;
                f = g + h;

                pq.push(node(ns, f, g+1));      
                visitMap[ns]=g+1;               // �̵�Ƚ�� üũ
            }
        }
        
        if(visitMap.count(TARGET)){
            cout << visitMap[TARGET] << "\n";
        }
        else{
            cout << "impossible" << "\n";
        }
    }
}