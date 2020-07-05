#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

  int i,top;
  char stack[101], str[101];
  bool check;

void push(){
  stack[top]=str[i];
  top++;
}
void pop(int x){
  if(stack[top-1]==str[i]-x) top--; //str[i]-x 아스키코드 참조
  else check= false;
}
int main() {
  while(true){
    fgets (str, 101, stdin);
    if (str[0] == '.') break;
    top=0;
    check = true;

    for(i=0;i<strlen(str);i++){
      if(str[i]=='(') push();
      if(str[i]=='[') push();
      if(str[i]==']') pop(2); // ] - 2 = [
      if(str[i]==')') pop(1); // ) - 2 = (
      if(str[i]=='.') break;

    }

    if(check && top==0) cout<< "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
