#include <iostream>

using namespace std;

int main(){
  int t,n,m;
  cin >> t;
  while(t--){
    cin >> n >> m;
    char map[n][m];
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> map[i][j];
      }
    }

    int cnt=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        int a=i;
        int b=j;
        while(true){
          if (map[a][b] == 'R'){
            if (b < m-1)b++;
            else {
              map[a][b] = 'D';
              a++;
              cnt++;
            }
          }
          else if (map[a][b] == 'D'){
            if (a < n-1)a++;
            else {
              map[a][b] = 'R';
              b++;
              cnt++;
            }
          } 
          else if (map[a][b] == 'C'){
            break;
          }
        }
      }
    }
    cout << cnt << "\n";

  }
  return 0;
}
