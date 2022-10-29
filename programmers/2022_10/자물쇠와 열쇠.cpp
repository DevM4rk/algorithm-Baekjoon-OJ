#include <bits/stdc++.h>

using namespace std;

int M,N;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> cp = key;
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            key[i][j] = cp[M-1-j][i];   //�ݽð����
        }
    }
}

bool bf(vector<vector<int>> &key, vector<vector<int>> board, int x, int y){
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            board[x+i][y+j]+=key[i][j]; // key, lock�� ���Ⱑ ������ 2�� ��
        }
    }
    
    for(int i=M-1; i<N+M-1; i++){
        for(int j=M-1; j<N+M-1; j++){
            if(board[i][j] != 1) return false;
        }
    }
    
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    M = key.size();
    N = lock.size();
    vector<vector<int>> board(N+2*(M-1), vector<int>(N+2*(M-1)));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            board[i+M-1][j+M-1] = lock[i][j];
        }
    }
    
    //�뺸��
    for(int r=0; r<4; r++){
        
        for(int i=0; i<N+M-1; i++){
            for(int j=0; j<N+M-1; j++){
                if(bf(key,board,i,j)){
                    return true;   
                }
            }
        }
        //�� ������ ȸ��
        rotate(key);
    }
    
    return false;
}
/*
�ڹ��迡 Ű�� ��� �뺸�� ����Ž������ ��,
Lock�� Key�� ũ�⸸ŭ �����¿�� �� Ű�� ������ �ϳ� �� �����ؾ� �� ��
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 1 1 1 0 0
0 0 1 1 0 0 0
0 0 1 0 1 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/