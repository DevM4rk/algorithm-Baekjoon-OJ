#include <iostream>
#include <vector>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

int N,T;
long arr[101]={0,1,1,1,2,2};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for(int i=6; i<=100; i++) arr[i] = arr[i-1] + arr[i-5];

    while(T--){
        cin >> N;

        cout << arr[N] << "\n";
    }
}
/*
p1  1
p2  1
p3  1
p4  2  p1+p3
p5  2  
p6  3  p1+p5
p7  4  p2+p6
p8  5  p3+p7
p9  7  p4+p8
*/