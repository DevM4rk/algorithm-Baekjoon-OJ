#include <iostream>

using namespace std;
int main() {

  int sum=0,N,M,save=0,arr[101];

  cin>> N >> M;
  for(int i=0;i<N;i++) cin>>arr[i];

  for(int i=0;i<N;i++){
    for(int j=1+i;j<N;j++){
      for(int k=1+j;k<N;k++){
        sum=arr[i]+arr[j]+arr[k];
         // printf("%d = %d + %d + %d \n",sum,i,j,k);
        if(sum<=M && save<sum ) save =sum;
      }
    }
  }
  printf("%d\n", save);
  return 0;
}
