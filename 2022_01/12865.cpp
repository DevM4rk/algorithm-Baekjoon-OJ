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

int n,k;
int w[101], v[101];
int d[101][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> k;
    for(int i=1; i<=n; i++)
        cin >> w[i] >> v[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(w[i] > j) d[i][j] = d[i-1][j];   // i��° ���Ժ��� ������ ��ƿ���ִ� ���԰� �� �۴ٸ� ���� �� ����, �� ���� �� ����
            else d[i][j] = max(d[i-1][j], d[i-1][j-w[i]] + v[i]);       //��ƿ���ִ¹��԰� ���ų� ũ�� ���� �� ����
                                                // ���� �ʾ������� �־��� ��, �� �� �� ū ������ �ʱ�ȭ
        }
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=k; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d[n][k];
}
/*
���� ������ i��° ������ �־��� ���� ���� �ʾ��� ��, �� �� �� ��ġ�� ū ���� �������� �Ǵ� ��
D[A][B] = C : A��° ���Ǳ��� �԰�, ������ ���԰� B�� �� ���濡 ��� ���ǵ��� ��ġ�� C

4 7
6 13
4 8
3 6
5 12

0 0 0 0 0 13 13 
0 0 0 8 8 13 13
0 0 6 8 8 13 14
0 0 6 8 12 13 14
*/