//90도 회전

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
  int n;    //n= 5 or 10
  cin >> n;
  int map[n][n];

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      cin >> map[i][j];
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
      cout << setw(2) << map[5-1-j][i] << " ";
    cout << "\n";
  }
  return 0;
}
  
/* n=5
(0,0) (0,1) (0,2) (0,3) (0,4)

(1,0) (1,1) (1,2) (1,3) (1,4)

(2,0) (2,1) (2,2) (2,3) (2,4)

(3,0) (3,1) (3,2) (3,3) (3,4)

(4,0) (4,1) (4,2) (4,3) (4,4)
*/
