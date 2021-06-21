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

int N, MAX=-1000000000, MIN=1000000000;
int arr[11]={0,};
int op[4]; // + - * /

void solve(int sum, int cnt){

    if( cnt == N ){
        MAX=max(sum,MAX);
        MIN=min(sum,MIN);
        return;
    }

    int temp = sum;
    for(int i=0; i<4; i++){
        if( op[i] == 0 ) continue;

        op[i]--;

        switch (i){
        case 0: // +
            sum+=arr[cnt];
            break;
        
        case 1: // -
            sum-=arr[cnt];
            break;

        case 2: // *
            sum*=arr[cnt];
            break;

        case 3: // /
            sum/=arr[cnt];
            break;
        }
        
        solve(sum, cnt+1);
        sum = temp;
        op[i]++;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    for(int i=0; i<4; i++)
        cin >> op[i];
    
    solve(arr[0], 1);

    cout << MAX << endl << MIN;
}