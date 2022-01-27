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

const string TARGET = "123456780";

string s;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;

queue<pair<string, int>> q; // open
set<string> check;          //close

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            char c;
            cin>>c;
            s += c;
        }
    }

    check.insert(s);
    q.push({s,0});      

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        string cstr = cur.first;
        int ccnt = cur.second;

        //순서대로 맞췄을 때, ans에 한번도 입력이 안들어왔거나 저장된 값보다 더 작은 경우 ans 값 초기화
        if(cstr == TARGET && (ans == -1 || ans > ccnt))
            ans = ccnt;
        
        int zero = cstr.find('0');
        int x = zero/3, y = zero%3;
        /*
        1 2 3   zero = 5
        4 5 0   x = 1, y = 2
        7 8 6
        */
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            string nstr = cstr;
            swap(nstr[x*3+y], nstr[nx*3+ny]); // 0과 상하좌우 위치 변경

            if(check.find(nstr) == check.end()){    //순서대로 맞춰진 것이 없다면
                check.insert(nstr);
                q.push({nstr,ccnt+1});
            }
        }
    }

    cout << ans;
}
