#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size(), m = board[0].size();
    int sum[1001][1001]={};
    
    //������ ���� �س���
    for(auto s : skill){
        int type = s[0], x = s[1], y = s[2], x1 = s[3], y1 = s[4], dam = s[5];
        if(type==2) dam *= -1; //ȸ����ų�� ��� -1�����ؼ� �ݴ���Էµ���
        
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

    //�� -> �� ���ϱ�
    for(int i=0; i<n; i++){
        for(int j=1; j<m; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    
    //��->�� ���ϱ�
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            sum[i][j] += sum[i-1][j];
        }
    }
    
    //board�� ���ϱ�
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
skill�鸸 ���� ���� ���鼭 ���������� üũ�ϴ°� ���ƺ��̴µ�
x,y / x1,y1 �־��� ���
�� �𼭸� ���� +1 ��ġ�� �ִ� ���� +4, �ƿ� �ݴ����� -4�� �־� +4+4-4�� ��Ⱑ��
����, �¿� for������ ���� ���鼭 sum ���ְ�
���� board�ǰ� sum ��ġ�鼭 0���� ������� check
-4    +4(x,y1+1)


+4    -4(x1+1, y1+1)
(x1+1,y)
*/