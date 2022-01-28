//boj 11112에서 조금 변형해서 저장함
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
//f 가능성, 가장 낮은것을 따라감 /  g 현재까지의 값, 움직인 횟수 /  h 앞으로 예상되는 값, 제자리에 있지 않은 퍼즐의 수
struct node{
    string board;// 노드의 모양
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
        if(a.f==b.f) return a.g > b.g;  // f가 같다면 g가 작은 순
        return a.f > b.f;               // f가 작은 순
    }
};

priority_queue<node, vector<node> ,cmp> pq; // open, 가능성이 가장 높아보이는(f값이 작은) 순으로 계산 진행
unordered_map<string, int> visitMap;        // close, 이미 봤던 모양을 또 가는 중복 방지, value는 이동횟수

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while(t--){

        //초기화
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

            // 모두 맞춘 경우 끝냄
            if(visitMap.count(TARGET)) break;

            int zero = cnode.board.find('#');
            int x = zero/3, y = zero%3;         // 0의 위치를 2차원 배열로 표시

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
                
                string ns = cnode.board;
                swap(ns[x*3+y], ns[nx*3+ny]);   // 0과 상하좌우 위치 변경
                if(visitMap.count(ns)) continue;// 이미 지나온 케이스면 패스

                int f=0,g=0,h=0;
                for(int j=0; j<ns.size(); j++)  // 휴리스틱 값(목표값) 구하기
                    if(ns[j] != TARGET[j]) h++; // 목표 노드가 되기 위해 다른 위치에 있는 숫자 체크
                g = cnode.g;
                f = g + h;

                pq.push(node(ns, f, g+1));      
                visitMap[ns]=g+1;               // 이동횟수 체크
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