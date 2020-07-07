#include <iostream>

using namespace std;

int main() {

  int cnt,M,N,save=100;
  char chess[50][50];

  cin>> N >> M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> chess[i][j];
    }
  }

for (int i = 0; i <= N - 8; i++) {		
		for (int j = 0; j <= M - 8; j++) {

			cnt = 0;
			for (int k = i; k < i + 8; k++) {		 //WBWBWBWB
				for (int l = j; l < j + 8; l++) {  //BWBWBWBW라고생각
          
          if((k+l)%2){   //홀수
            if(chess[k][l]=='B') cnt++;
          }
          else{      //짝수
            if(chess[k][l]=='W') cnt++;
          }
        }
			}

			save = min(save, cnt);		  
			save = min(save, 64 - cnt);	//두가지 중 한가지만 값을 찾아도 64에서 나온 값을 빼면 나머지 한가지의 값을 알 수 있음.
		}
	}
  printf("%d \n", save);
  return 0;
}
/*
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44
*/
