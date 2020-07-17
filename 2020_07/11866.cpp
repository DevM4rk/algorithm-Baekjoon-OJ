#include <iostream>
#include <queue>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
  int N,K,a; 
  queue<int> q;
  cin >> N >> K;

  for(int i=1; i<=N ; i++) q.push(i);
cout << "<" ;
  while(N--){
    
    for(int i=0 ; i<K ; i++){
      if(i!=(K-1)){
        a = q.front();
        q.pop();
        q.push(a);
      }
      else{
        a = q.front();
        q.pop();
        cout << a ;
      }
    }
    if (N==0) break;
   cout << ", ";
  }
cout << ">";



  return 0;
}
