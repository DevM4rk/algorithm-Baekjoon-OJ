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
int a[301], d[301];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    d[1] = a[1];
    d[2] = a[1] + a[2];
    d[3] = a[3] + max(d[1], a[2]);  //��⵵ ����

    for(int i=4; i<=n; i++)
        d[i] = a[i] + max(d[i-3]+a[i-1], d[i-2]);

    cout << d[n];
}
/*
d ���̺��� ���� : ��� ���� �� �Ǵ� �͸� ����ؼ� ���� �ִ밪
d[n] ��� �� ����� ��
1. n-1 ����� ���Ϸ��� �� ��, n-2�� ���Ŀ�����ȵ� a[n-1] + d[n-3]
2. n-2 ����� ���Ϸ��� �� ��, ������ ���ߵ� ������� d[n-2]
*/