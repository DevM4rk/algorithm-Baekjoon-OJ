#include <stdio.h>

int main() {
    int stacki=0,n,top=0,x,resi=0,stack[100000];
    char res[200000];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
      scanf("%d",&x);
      if(top<x){
        for(;top<x;top++){
          stack[stacki++]=top+1;
          res[resi++]='+';
        }
      }
      else {
        if(stack[stacki-1]!=x) {
          printf("NO\n");
          return 0;
        }
      }
      stacki--;
      res[resi++]='-';
      //for(int j=0;j<top;j++) printf("[%d]",stack[j]);
    }
    for(int i=0;i<resi;i++) printf("%c\n",res[i]);;
  
  return 0;
}
