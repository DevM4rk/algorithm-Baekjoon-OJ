#include <iostream>

using namespace std;

int main() {

  int N,vs=0,x[200]={0, },y[200]={0, };

  cin>> N;

 for(int i=0;i<N;i++){
    cin >> x[i] >> y[i];
  }

  for(int i=0;i<N;i++){
    vs=1;
    for(int j=0;j<N;j++){
      if(x[i]<x[j] && y[i]<y[j]) vs++;
    }
    printf("%d ",vs);  
  }
  
  return 0;
}
