#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    std::string a = "Hello World";
string b;

    std::cout << "a: \"" << &a << "\"\n"; // a는 비어있음
    std::cout << "b: \"" << &b << "\"\n"; // b가 원래 값 가져감

    b = std::move(a); // 이동

    std::cout << "a: \"" << &a << "\"\n"; // a는 비어있음
    std::cout << "b: \"" << &b << "\"\n"; // b가 원래 값 가져감
}