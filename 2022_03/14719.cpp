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

int block[501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    for(int i=0; i<m; i++)
        cin >> block[i];

    int ans=0, top=0;
    stack<int> s;

    for(int i=0; i<m; i++){
        if(top <= block[i]){
            int sum=0;
            while(!s.empty()){
                sum += top - s.top();
                s.pop();
            }
            ans += sum;
            
            top = block[i];
        }
        else{
            s.push(block[i]);
        }
    }

    if(s.size() >= 2){
        int sum=0, last=s.top(); s.pop();
        while(!s.empty()){
            if(s.top() < last){
                sum += last - s.top();
            }
            else{
                last = s.top();
            }
            s.pop();
        }

        ans += sum;
    }

    cout << ans;
}
//1:35 ~ 1:47
// �ѵδ����� ���ص� �ȵǰ� �� Ǯ�����ǵ� �׳�Ǯ����
// ���� ��� ������ top���� ����, �׺��� �����͵��� ���ÿ� �ְ� ���� ��հ� ���ų� �Ѵ� ũ�Ⱑ ���� ���� ���鼭 �ջ��ϰ�
// top ��� �ʱ�ȭ, �ݺ�
// �׷��ԵǸ� ����2���� ���ó�� top���� ū ���� �ȳ����� �Ǹ�, ���ÿ� �����ִ� �ֵ��� ����
// ������ 1�� ����������� ���� ���� ���� ������ ����� 2�̻��� ��츸 ���
// ���ʱ���� �̹� top���� �����ְ��ֱ⶧���� top������ �����ʱ������ �ΰ� ������ �������鼭 �׺��� ũ�� �ʱ�ȭ, ������ �ջ�