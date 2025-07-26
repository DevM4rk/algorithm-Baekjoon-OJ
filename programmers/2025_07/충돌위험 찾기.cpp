#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>

using namespace std;
map <tuple<int,int,int>,int> log;

    int answer = 0;

struct st{
    int num,target,x,y, cnt;
    st(int a, int b,int c,int d, int e){
        this->num = a;
        this->target = b;
        this->x = c;
        this->y = d;
        this->cnt = e;
    }
};

void check(int x, int y, int cnt){
    log[{x,y,cnt}]++;
    if(log[{x,y,cnt}] == 2) answer++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    
    queue<st> q;
    for(int i=0; i<routes.size(); i++){
        auto r = routes[i];
        auto p = points[r[0]-1];
        
        q.push(st(i,1,p[0],p[1],0));
        check(p[0],p[1],0);
    }
    
    while(!q.empty()){
        auto [num,target,x,y,cnt] = q.front(); q.pop();
        for(int i=1; i<routes[num].size(); i++){
            int t = routes[num][i]-1;
            int tx = points[t][0];
            int ty = points[t][1];
            
            while(x != tx){
                if(x > tx) x--;
                else x++;

                cnt++;
                check(x,y,cnt);
            }
            while(y != ty){
                if(y > ty) y--;
                else y++;

                cnt++;
                check(x,y,cnt);
            }
        }
    }
    
    return answer;
}

/*
x가 같기전까지 크거나작다면 x이동 +1 -1
같아지면 y 이동 

q는 필요없는데 풀다가 중간에 꺾다보니 이렇게됐네 다시풀기 귀찮
*/