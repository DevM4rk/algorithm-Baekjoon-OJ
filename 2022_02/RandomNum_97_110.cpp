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

const int MIN = 97;
const int MAX = 110;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr); cout.tie(nullptr);

    cout << "계속하려면 아무 문자 입력 후 엔터를 누르시오. \n"
        << "※ 주의 : 1초마다 초기화 됨. \n\n";

    string k; 
    while(1){
        cin >> k;
        
        srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
    
        // 난수 %10 = 난수의 범위 0~9까지 한정
        for(int i=0; i<5; ++i){
            float a;
            while(1){
                a = rand() % 110;
                if( 97 <= a && a < 110 ) break;
            }
            a += + float(rand() % 10)/10;
            cout << setw(6) << a << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}