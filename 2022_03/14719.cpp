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

int block[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> block[i];

    int ans=0, top=0;
    stack<int> s;

    for(int i=0; i<m; i++){
        if(top <= block[i]){
            int sum=0;
            while(!s.empty()){
                sum += top - s.top();
                s.pop();
            }
            ans += sum;
            
            top = block[i];
        }
        else{
            s.push(block[i]);
        }
    }

    if(s.size() >= 2){
        int sum=0, last=s.top(); s.pop();
        while(!s.empty()){
            if(s.top() < last){
                sum += last - s.top();
            }
            else{
                last = s.top();
            }
            s.pop();
        }

        ans += sum;
    }

    cout << ans;
}
//1:35 ~ 1:47
// 한두달전엔 이해도 안되고 못 풀었던건데 그냥풀었네
// 왼쪽 기둥 기준을 top으로 설정, 그보다 작은것들은 스택에 넣고 왼쪽 기둥과 같거나 넘는 크기가 오면 스택 비우면서 합산하고
// top 기둥 초기화, 반복
// 그렇게되면 예제2번의 경우처럼 top보다 큰 놈이 안나오게 되면, 스택에 남아있는 애들이 있음
// 스택이 1개 남아있을경우 고일 수가 없기 때문에 사이즈가 2이상인 경우만 고려
// 왼쪽기둥은 이미 top으로 받쳐주고있기때문에 top기준을 오른쪽기둥으로 두고 스택을 꺼내보면서 그보다 크면 초기화, 작으면 합산