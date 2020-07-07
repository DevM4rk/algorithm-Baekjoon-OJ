#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

  int stacki,i,n,top,x,resi,stack[100000];
  char res[200000];
  bool check;
  
void push(){
  stack[stacki++]=top+1;
  res[resi++]='+';
}

void pop(){
  stacki--;
  res[resi++]='-';
}

int main() {
    cin>>n;
    top=0;
    stacki=0;
    resi=0;
    check=true;
    for(i=0;i<n;i++){
      cin>>x;
      if(top<x){
        for(top<x;top++) push();
      }
      else {
        if(stack[stacki-1]!=x) check = false;  
      }
      pop();
      //for(int j=0;j<top;j++) printf("[%d]",stack[j]);
    }
    if (check){
      for(int j=0;j<resi;j++) cout<<res[j]<<endl;
    }
    else cout<< "NO" << endl;
  return 0;
}
