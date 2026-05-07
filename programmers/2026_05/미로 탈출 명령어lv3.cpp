#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
string dc = "dlru";

string solution(int n, int m, int xx, int yy, int r, int c, int k) {
    string answer = "";
    int cnt=0;
    n++; m++;
    
    if( (abs(xx-r) + abs(yy-c)) % 2 != k % 2 || (abs(xx-r) + abs(yy-c)) > k) return "impossible";
    
    priority_queue<pair<string,pair<int,int>>, vector<pair<string,pair<int,int>>>, greater<pair<string,pair<int,int>>>> q;
    q.push({"",{xx,yy}});
    
    while(!q.empty()){
        auto [ans,loc] = q.top(); q.pop();
        auto [x,y] = loc;
        // cout << x << y << ans << endl;
        
        if((abs(x-r) + abs(y-c)) > k-ans.size()) continue;  // 이게 핵심이네
        if((abs(x-r) + abs(y-c)) % 2 != (k-ans.size()) % 2) continue;
        if(x == r && y == c && ans.size() == k){
            return ans;
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            string nans = ans + dc[i];
            if(nx < 1 || ny < 1 || nx >= n || ny >= m ) continue;
            q.push({nans,{nx,ny}});
        }
    }
    
    return answer;
}
/*
1:20 ~
bfs로
x-r y-c 가 짞수인데 k가 홀수이면 불가능 그 반대도 마찬가지
dlru 순서

1. 이미 도착했고 k까지 남은 경우엔 가능하면 dudu lrlr rlrl udud 반복해야함

2. 50 50 1 1 50 50 2500 으로 가정해도 도착까지 최대 100칸만에는 무조건 도착지점에 도달함
아  아니네
dddddd최대한 가고 중간에 lrlrlr 반복한후 마지막에 rrrrrr로 채워지겠네..

아래모두 k가 여유있는경우
도착지점이 시작점보다 좌하인 경우
dddddddllllllll할수있을떄까지 하고, 즉 0,0 까지 가고 rlrlrl 반복한후에 r u 로 자리찾기 <<<<<<이게정답
도착지점이 시작점보다 좌상인 경우
dddddddllllllll  위와 동일
우하인 경우 동일
우상인경우 동일
*/