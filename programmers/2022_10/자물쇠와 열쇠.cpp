#include <bits/stdc++.h>

using namespace std;

int M,N;

void rotate(vector<vector<int>> &key){
    vector<vector<int>> cp = key;
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            key[i][j] = cp[M-1-j][i];   //반시계방향
        }
    }
}

bool bf(vector<vector<int>> &key, vector<vector<int>> board, int x, int y){
    
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            board[x+i][y+j]+=key[i][j]; // key, lock의 돌기가 만나면 2가 됨
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
    
    //대보기
    for(int r=0; r<4; r++){
        
        for(int i=0; i<N+M-1; i++){
            for(int j=0; j<N+M-1; j++){
                if(bf(key,board,i,j)){
                    return true;   
                }
            }
        }
        //안 맞으면 회전
        rotate(key);
    }
    
    return false;
}
/*
자물쇠에 키를 모두 대보며 완전탐색으로 비교,
Lock에 Key의 크기만큼 상하좌우로 더 키운 보드판 하나 더 생성해야 할 듯
0 0 0 0 0 0 0 
0 0 0 0 0 0 0 
0 0 1 1 1 0 0
0 0 1 1 0 0 0
0 0 1 0 1 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
*/