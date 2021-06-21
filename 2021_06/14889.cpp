#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N, MIN = 1000000000;
int arr[20][20];
bool visited[20] = {false,};

void solve(int idx, int cnt){

    if( cnt == N/2 ){
        
        int start, link;
		start = 0;
		link = 0;

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if (visited[i] == true && visited[j] == true) start += arr[i][j];
				if (visited[i] == false && visited[j] == false) link += arr[i][j];
            }
        }

		int temp = abs(start - link);
		if (MIN > temp) MIN = temp;

        return;
    }

    for(int i=idx; i<N; i++){
        if( visited[i] == true ) continue;
        
        visited[i] = true;
        solve(i, cnt+1);
        visited[i] = false;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> arr[i][j];

    solve(0, 0);

    cout << MIN;
}