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

int N, root, arr[1000000][2];

void postorder(int x){
    if (x == 0) return;
    postorder(arr[x][0]);
    postorder(arr[x][1]);
    cout << x << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> root;

    while(cin >> N){
        int rt = root;

        while(true){    //첨에 이걸 한 뒤, r을 바꿔가며 반복
            
            if(N < rt){     //좌측

                if(arr[rt][0] == 0){ //좌측이 비었으면 입력 후 break;
                    arr[rt][0] = N;
                    break;
                }
                else{   //안비었으면 r 바꾸고 반복
                    rt = arr[rt][0];
                }
            }
            else{       //우측
                
                if(arr[rt][1] == 0){
                    arr[rt][1] = N;
                    break;
                }
                else{
                    rt = arr[rt][1];
                }
            }
        }
    }
    

    postorder(root);
}