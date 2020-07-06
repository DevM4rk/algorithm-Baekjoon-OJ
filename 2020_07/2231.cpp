#include <iostream>

using namespace std;

int main() {

  int i,N,sum,temp;

  cin>> N;

  for(i=1;i<N;i++){
    sum=i;
    temp=i;
    
   while(temp!=0){
      sum+=temp%10;
      temp/=10;
    }

    if(sum==N){
      cout << i;
      return 0;
    }
  }

  cout<<"0";
  return 0;
}
