#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int ans = 0;
    sort(rocks.begin(), rocks.end());
    
    int s=0, e=distance, m;
    
    while(s<e){
        m=(s+e)/2;
        
        int cnt=0, temp=0;
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i]-temp < m) cnt++;
            else temp = rocks[i];
        }
        
        if(distance-temp < m) cnt++;
        
        cout << s << " " << m << " " << e << " " << cnt << endl;
        
        if(cnt<=n){             // cnt�� ���� ������ ����n ���� �۰ų� ����
            if(ans < m) ans=m;  // ���� �亸�� m�� ū ��찡 �� (n���� �ƴ� �� ���Ϲۿ� ���Ű� �ȵǴ� ����� �� ���)
            s=m+1;
        }
        else{
            e=m;
        }
        
    }
    
    return ans;
}
/*
0  2 11 14 17 21 25
 2  9  3  3  4  4
m = �Ÿ��� �ּڰ�
���� 3�̶�� 3���� �������� �� ���� ���ְ� ī��Ʈ�ؾ���
0  11  14  17  21 25 
 11
 cnt�� 2���� ������ s�� ����
 
*/