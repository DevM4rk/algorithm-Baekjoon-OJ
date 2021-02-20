#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int N, temp;
    vector <int> v;
    stack <int> s;
    
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> temp;
        v.push_back(temp);
    }

    vector <int> ans (v.size(), -1);

    for(int i=0; i<v.size(); i++){

        while(!s.empty() && v[s.top()] < v[i]){
            ans[s.top()] = v[i];
            s.pop();
        }
        
        s.push(i);
    }
    for(int x : ans) cout << x << " ";
}

/*
3 5 2 7
top down case
7���� �� temp 2
7���� �� temp 5
������ temp�� ���ҰԾƴ϶� �� ���̿� ū ���� ���� ��쵵 �����ؾߴ�
���� 0 
v[0] < v[1] �� ��찡 ���� �� ���� �ݺ�
ans[0] = v[1];
���� 0 1
v[1] < v[2] = 2 �� ���Ǿȵ� �н�
���� 0 1 2
v[2] < v[3] ���� ����
ans[2] = v[3];
s.pop();
v[1] < v[3] ���� ����
ans[1] = v[3];

ans [5, 7 ,7]
�̰� ������ ����
������ ���� ans �� �Է� �ȵȰ��� üũ�ϰ� �Ѿ
���� ��쿡�� �Ѿ
�� �������µΰ�����찡����
5 2 6
5�� ������ ū���
�׳� �帧�� �°� �����
5 2 4
5�� ������ �������
���ÿ� ���� ���Ϲ� �Ѿ
�׷��� ������ -1 �� �ʱ�ȭ�� �س����� ��� ����

54321�� ���
-1-1-1-1-1

*/