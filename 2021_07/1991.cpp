#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int N, arr[26][2];

void preorder(int x){
    if (x == -1) return;
    cout << (char)(x+'A');
    preorder(arr[x][0]);
    preorder(arr[x][1]);
}

void inorder(int x){
    if (x == -1) return;
    inorder(arr[x][0]);
    cout << (char)(x+'A');
    inorder(arr[x][1]);
}

void postorder(int x){
    if (x == -1) return;
    postorder(arr[x][0]);
    postorder(arr[x][1]);
    cout << (char)(x+'A');
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    
    while(N--){
        char a, b, c;
        cin >> a >> b >> c;

        a -= 'A';
        
        if(b == '.') 
            arr[a][0] = -1;
        else 
            arr[a][0] = b - 'A';
        
        if(c == '.') 
            arr[a][1] = -1;
        else 
            arr[a][1] = c - 'A';
    }

    preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
}