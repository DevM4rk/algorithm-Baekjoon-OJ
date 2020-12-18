#include <iostream>
#include <cmath>

using namespace std;

int N, x, y;

void solve(){
    while(N--){
        cin >> x >> y;
        int path = y-x;
        int i = floor(sqrt(path));
        
        if( pow(i,2) == path ) cout << i*2-1 << endl;
        else if (path <= pow(i,2)+i) cout << i*2 << endl;
        else cout << i*2+1 << endl;
    }
}

int main(){
    cin >> N;

    solve();
}
/* i*2-1 의 값이 count
i  count  c+1 c+2
1    1     1   2
2    3     2   3
3    5     3   4
4    7     4   5
5    9     5   6
*/

/* path가 i 보다 +1 
1  1
2  1 1             1
3  1 1 1           2
4  1 2 1           
5  1 2 1 1         2
6  1 2 2 1
7  1 2 2 1 1       3
8  1 2 2 2 1
9  1 2 3 2 1
10 1 2 3 2 1 1     3
11 1 2 3 2 2 1
12 1 2 3 3 2 1
13 1 2 3 2 2 2 1   4
14 1 2 3 3 2 2 1
15 1 2 3 3 3 2 1
16 1 2 3 4 3 2 1  
17 1 2 3 4 3 2 2 1  4 
18 1 2 3 4 3 3 2 1
                    5
25 1 2 3 4 5 4 3 2 1 
*/
