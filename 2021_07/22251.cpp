#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

vector<int> table[7] = {
	   //0, 1, 2, 3, 4, 5, 6
		{1, 1, 1, 0, 1, 1, 1}, //0
		{0, 0, 1, 0, 0, 0, 1}, //1      _
		{1, 0, 1, 1, 1, 1, 0}, //2     |_|
		{1, 0, 1, 1, 0, 1, 1}, //3     |_|
		{0, 1, 1, 1, 0, 0, 1}, //4
		{1, 1, 0, 1, 0, 1, 1}, //5
		{1, 1, 0, 1, 1, 1, 1}, //6
		{1, 0, 1, 0, 0, 0, 1}, //7
		{1, 1, 1, 1, 1, 1, 1}, //8
		{1, 1, 1, 1, 0, 1, 1}, //9
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k, p, x; cin >> n >> k >> p >> x;
    
}