#include <iostream>
#include <queue>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
  int N,n; 
  string str;
  queue<int> q;
  cin >> N;

  while(N--){
    cin >> str;
    if (str == "push"){
      cin >> n;
      q.push(n);
    }
    else if (str == "front"){
      if(q.size() != 0){
        cout << q.front() << "\n";
      }
      else{
        cout << "-1" << "\n";
      }
      
    }
    else if (str == "back"){
      if(q.size() != 0){
        cout << q.back() << "\n";
      }
      else{
        cout << "-1" << "\n";
      }
    }
    else if (str == "size"){
      cout << q.size() << "\n";
    }
    else if (str == "empty"){
        cout <<  q.empty() << "\n";
    }
    else if (str == "pop"){
      if(q.size() != 0){
        cout << q.front() << "\n";
        q.pop();
      }
      else{
        cout << "-1" << "\n";
      }
    }

  }
  return 0;
}
