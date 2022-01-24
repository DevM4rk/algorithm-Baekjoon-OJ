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

int n;
int a[301], d[301][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];

    d[1][0] = a[1];
    d[1][1] = 0;
    d[2][0] = a[1]+a[2];
    d[2][1] = a[2];

    for(int i=3; i<=n; i++){
        d[i][0] = d[i-1][1] + a[i];
        d[i][1] = max(d[i-2][0], d[i-2][1]) + a[i]; 
    }

    cout << max(d[n][0], d[n][1]);
}
/*
d[i][j] = ���� j����� ��� i���� ���� �� ���� ���� �ִ밪
0 - ù������� ���� ���
1 - �ΰ������ ���� ���
d[i][0] = d[i-1][1] + a[i]; // ������ �ΰ�� ���Ծ����, ù����̸� ����3������
d[i][1] = max(d[i-2][0], d[i-2][1]) + a[i]; ���� �� ������� ������� i-2�� ù����̵� �ΰ���� ���Ե� ���x

max(d[n][0] , d[n][1]);
*/