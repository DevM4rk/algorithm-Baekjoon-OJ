#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> a(rows+1, vector<int>(columns+1, 0));
    
    int p=0;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            p++;
            a[i][j]=p;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        
        queue<int> q;
        q.push(a[x1][y1]);
        int MIN = a[x1][y1], next;
        
        for(int y=y1; y<y2; y++){
            q.push(a[x1][y+1]);
            next = q.front();
            a[x1][y+1] = next;
            MIN = min(MIN, next); 
            q.pop();
        }
        
        for(int x=x1; x<x2; x++){
            q.push(a[x+1][y2]);
            next = q.front();
            a[x+1][y2] = q.front();            
            MIN = min(MIN, next); 
            q.pop();
        }
        
        for(int y=y2; y>y1; y--){
            q.push(a[x2][y-1]);
            next = q.front();
            a[x2][y-1] = q.front();
            MIN = min(MIN, next); 
            q.pop();
        }
        
        for(int x=x2; x>x1; x--){
            q.push(a[x-1][y1]);
            next = q.front();
            a[x-1][y1] = q.front();
            MIN = min(MIN, next); 
            q.pop();
        }
        answer.push_back(MIN);
    }
    
    // for(int i=1; i<=rows; i++){
    //     for(int j=1; j<=columns; j++){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    
    return answer;
}
/*
10:47 ~ 11:35
0���ͽ����̾ƴ϶� 1���� <=x �������� ����!!!!

���� x1,y1,x2,y2
���� ������ 
int [rows+1][c+1];
for�����鼭 ���� ������� ä���

2,2 - 2,4
   
5,2 - 5,4
ù��°���� y1���� y2����
�ι�° x1�� x2����
�� y2 y1
�� x2 x1

�׵θ� �� �� min���� �ּҰ� ã�Ƴ��� answer�� Ǫ�� - ans�ʿ�
*/