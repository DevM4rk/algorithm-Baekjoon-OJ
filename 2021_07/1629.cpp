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

long long a, b, c;
int result = 0;
long long pow(long long x, long long m) {
 
    if (m == 0)
        return 1;
    else if (m == 1)
        return x;

    if (m % 2 == 1)
        return pow(x, m - 1)*x % c;
    else{
        long long half = pow(x, m / 2) % c;
        return (half * half) % c;
    }
}
 
int main() {
 
    cin >> a >> b >> c;

    cout << pow(a, b) % c;
 
    return 0;
}
//1629