#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

int main() {

  int top;
  char str[101];
  char stack[101];
  bool check;

  while(true){
    memset(str, 0, strlen(str));
    memset(stack, 0, strlen(stack));
    top=0;
    check = true;

    fgets (str, 101, stdin);
    if (str[0] == '.') return 0;

    for(int i=0;i<strlen(str);i++){
      
      if(str[i]=='('){
        stack[top]='(';
        top++;
      }
      else if(str[i]=='['){
        stack[top]='[';
        top++;
      }
      else if(str[i]==']'){
        if (top==0){
          check= false;
          break;
        }
        else if(stack[top-1]=='[') top--;
        else break;
      }
      else if(str[i]==')'){
        if (top==0){
          check= false;
          break;
        }
        else if(stack[top-1]=='(') top--;
        else break;
      }
      else if(str[i]=='.') break;
      else ;

      //cout << "stack : " << stack[top-1] <<" , top : " << top << endl;

    }

    if(check && top==0) cout<< "yes" << endl;
    else cout << "no" << endl;

  }
  return 0;
}
