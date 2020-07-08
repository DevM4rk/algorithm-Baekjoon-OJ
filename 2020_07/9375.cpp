#include <iostream>
#include <map>

using namespace std;

int main() {
  
  map< string, int > m;
  map< string, int >::iterator m_iter;

  int num,n,sum;
  string name,kind;

  cin >> num;
  for(int i=0;i<num;i++){
    cin >> n;
    sum=1;
   
    for(int j=0;j<n;j++){
      cin >> name >> kind;

      auto m_iter = m.find(kind);
      if( m_iter ==m.end()){
        m.insert(make_pair(kind, 1));
      }
      else{
       (*m_iter).second++;
      }
    }
    for(auto it = m.begin(); it != m.end(); it++){
		  sum *= (it->second)+1;
	  }
    cout << sum-1 << endl;
    m.clear();
  }

  return 0;
}

/*
aa bbb c

공식
a    b    c
(2+1)(3+1)(1+1) -1
*/
