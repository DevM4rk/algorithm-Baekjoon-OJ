#include <bits/stdc++.h>

using namespace std;

int n;
int rmax;
vector<int> ap;
vector<int> answer;

void dfs(int cnt,int idx, vector<int> &ry){  // cnt는 맞출 수 있는 화살의 개수 
    if(cnt == 0 || idx == 11){
        int asum=0, rsum=0; // 어피치 , 라이언 점수
        for(int i=0; i<=10; i++){
            //둘다 0이면 패스
            if(ap[i] == 0 && ry[i] == 0) continue;
            //라이언이 더크면 점수 10-i ?
            else if(ap[i] < ry[i]) rsum+= 10-i;
            //어피치가 더 크거나 같으면 점수 
            else if(ap[i] >= ry[i]) asum+= 10-i;
        }
        int sum = rsum - asum;  // 이거 안해줘도 되는 줄 알았는데 해줘야 점수받네 이것때문에 4시간은날린것같은데 왜지  그냥 라이언 점수만 보고 어떻게든 점수 많이 받기만하면되는거아닌가
        //아 어피치의 점수도 달라지는구나 ,, 그냥 바보였네
        
        //어피치보다 라이언이 클 경우 해당 점수판 저장 , 점수저장변수, 점수판벡터
        // 점수저장되어있는것보다 클 경우도 함께 고려, 맞다면 초기화,  점수판벡터도 초기화
        
        
       if(asum < rsum){
        // cout << asum << " " << rsum << " " << rmax << endl;
        // for(auto a : ry) cout << a << " ";
        // cout << endl;
            if(cnt > 0) ry[idx-1] = cnt;
           
            if(rmax == sum){
    // 남아있는 점수판 벡터를 10부터 찾아가면서 제일먼저 발견되는 경우 리턴, 그중에서 더 큰값 리턴
                for(int i=10; i>=0; i--){
                    int a = answer[i], r = ry[i];
                    if(a<r){
                        answer = ry;
                        break;
                    }
                    else if(a>r){
                        break;
                    }
                }
            }
            else if(sum > rmax){
                rmax = sum;
                //answer.clear();
                answer = ry;
            }
           ry[idx-1] = 0;
        }
        return;
    }
    
    
    for(int i = idx; i<=10; i++){ 
        //cout << ap[i] << " " << cnt << endl;
        if(ap[i] < cnt){
            cnt-= (ap[i] + 1);
            ry[i] = ap[i] + 1;
             //for(auto a : v) cout << a << " ";
             //cout << endl;
            
            dfs(cnt,i+1,ry);
            cnt += (ap[i] + 1);
            ry[i] = 0;
        }
        else{
            dfs(cnt,i+1,ry);    //안쏘는 경우
        }
    }
}

vector<int> solution(int nn, vector<int> info) {
    vector<int> ryan(info.size(), 0);
    ap = info;
    rmax = 0;
    n = nn;
    
    dfs(n,0,ryan);
    
    // 없다면 -1 푸쉬
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
/**10시 45분까지 // 앞 3문제 완료
7:00 ~ 8:15 밥먹고옴 9:20 ~ 35  45점..
재귀 돌려야함
맞춰서 이길경우 / 안맞추고 넘어갈 경우
그래서 같은 개수로 쏘는 경우는 없다
어피치가 맞춘 개수 기준 +1 이거나 / 0이거나의 경우의 수 2가지
*/