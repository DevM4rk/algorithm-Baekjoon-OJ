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

int dp[100001][5][5];
vi v;

int move(int from, int to){
    if(from==0) return 2;               // �ʱⰪ�� ���
    else if(from-to == 0) return 1;     // ���� �ڸ��� ���
    else if(abs(from-to) == 2) return 4;// �ݴ����� ���
    else return 3;                      // �ٷ� ���� ���
}

int dfs(int n, int l, int r){
    if(v.size() == n) return 0; //���� ��� - ������ Ȯ���� ���
    int& ret = dp[n][l][r];     //����������� �Ѱ���
    if(ret!=0) return ret;      //���� ��� - �̹� ����� ���� ���
    
    //����, ������ �ΰ����� ���� �ű涧 �ּҰ�
    return ret = min( dfs(n+1, v[n], r) + move(l, v[n]),
                        dfs(n+1, l, v[n]) + move(r, v[n]) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1){
        int a; cin >> a;
        if(a==0) break;
        v.push_back(a);
    }

    cout << dfs(0,0,0) << endl;
}