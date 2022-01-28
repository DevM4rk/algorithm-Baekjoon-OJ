#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    int sum[1001][1001]={};
    
    //누적합 구현 해놓기
    for(auto s : skill){
        int type = s[0], x = s[1], y = s[2], x1 = s[3], y1 = s[4], dam = s[5];
        if(type==2) dam *= -1; //회복스킬일 경우 -1을곱해서 반대로입력들어가게
        
        sum[x][y] += -dam;
        sum[x1+1][y1+1] += -dam;
        sum[x1+1][y] += dam;
        sum[x][y1+1] += dam;
    }
    
    // //debug
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //좌 -> 우 합하기
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    
    //상->하 합하기
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            sum[i][j] += sum[i-1][j];
        }
    }
    
    //board랑 합하기
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] + sum[i][j] > 0) answer++;
            board[i][j] += sum[i][j];
        }
    }
    
//     //debug
//     for(int i=0; i<n; i++){
//         for(int j=0; j<m; j++){
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }
    
    return answer;
}
/*
skill들만 먼저 따로 돌면서 누적합으로 체크하는거 좋아보이는디
x,y / x1,y1 주어질 경우
각 모서리 마다 +1 위치에 있는 곳에 +4, 아예 반대편에는 -4를 둬야 +4+4-4로 상쇄가능
상하, 좌우 for문으로 각각 돌면서 sum 해주고
기존 board판과 sum 합치면서 0보다 작은경우 check
-4    +4(x,y1+1)


+4    -4(x1+1, y1+1)
(x1+1,y)
*/