#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()
#define MAX 2187

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, zero=0, one=0, minor_one=0;
int arr[MAX][MAX]={0,};

void solve(int x, int y, int n){
    int temp = arr[x][y];
    int cnt = 0;

    for(int i=x; i<x+n; i++)
        for(int j=y; j<y+n; j++)
            if(arr[i][j] == temp) cnt++;

    if( cnt == n*n){
        switch (temp)
        {
        case -1:
            minor_one++;
            break;
        
        case 0:
            zero++;
            break;

        case 1:
            one++;
            break;
        }
    }
    else{
        int m = n/3;
        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            solve(x+i*m, y+j*m, m);
        }
    }
 
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];
    
    solve(0,0,N);

    cout << minor_one << endl;
    cout << zero << endl;
    cout << one << endl;
}