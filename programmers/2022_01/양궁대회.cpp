#include <bits/stdc++.h>

using namespace std;

int n;
int rmax;
vector<int> ap;
vector<int> answer;

void dfs(int cnt,int idx, vector<int> &ry){  // cnt�� ���� �� �ִ� ȭ���� ���� 
    if(cnt == 0 || idx == 11){
        int asum=0, rsum=0; // ����ġ , ���̾� ����
        for(int i=0; i<=10; i++){
            //�Ѵ� 0�̸� �н�
            if(ap[i] == 0 && ry[i] == 0) continue;
            //���̾��� ��ũ�� ���� 10-i ?
            else if(ap[i] < ry[i]) rsum+= 10-i;
            //����ġ�� �� ũ�ų� ������ ���� 
            else if(ap[i] >= ry[i]) asum+= 10-i;
        }
        int sum = rsum - asum;  // �̰� �����൵ �Ǵ� �� �˾Ҵµ� ����� �����޳� �̰Ͷ����� 4�ð��������Ͱ����� ����  �׳� ���̾� ������ ���� ��Ե� ���� ���� �ޱ⸸�ϸ�Ǵ°žƴѰ�
        //�� ����ġ�� ������ �޶����±��� ,, �׳� �ٺ�����
        
        //����ġ���� ���̾��� Ŭ ��� �ش� ������ ���� , �������庯��, �����Ǻ���
        // ��������Ǿ��ִ°ͺ��� Ŭ ��쵵 �Բ� ���, �´ٸ� �ʱ�ȭ,  �����Ǻ��͵� �ʱ�ȭ
        
        
       if(asum < rsum){
        // cout << asum << " " << rsum << " " << rmax << endl;
        // for(auto a : ry) cout << a << " ";
        // cout << endl;
            if(cnt > 0) ry[idx-1] = cnt;
           
            if(rmax == sum){
    // �����ִ� ������ ���͸� 10���� ã�ư��鼭 ���ϸ��� �߰ߵǴ� ��� ����, ���߿��� �� ū�� ����
                for(int i=10; i>=0; i--){
                    int a = answer[i], r = ry[i];
                    if(a<r){
                        answer = ry;
                        break;
                    }
                    else if(a>r){
                        break;
                    }
                }
            }
            else if(sum > rmax){
                rmax = sum;
                //answer.clear();
                answer = ry;
            }
           ry[idx-1] = 0;
        }
        return;
    }
    
    
    for(int i = idx; i<=10; i++){ 
        //cout << ap[i] << " " << cnt << endl;
        if(ap[i] < cnt){
            cnt-= (ap[i] + 1);
            ry[i] = ap[i] + 1;
             //for(auto a : v) cout << a << " ";
             //cout << endl;
            
            dfs(cnt,i+1,ry);
            cnt += (ap[i] + 1);
            ry[i] = 0;
        }
        else{
            dfs(cnt,i+1,ry);    //�Ƚ�� ���
        }
    }
}

vector<int> solution(int nn, vector<int> info) {
    vector<int> ryan(info.size(), 0);
    ap = info;
    rmax = 0;
    n = nn;
    
    dfs(n,0,ryan);
    
    // ���ٸ� -1 Ǫ��
    if(answer.empty()) answer.push_back(-1);
    return answer;
}
/**10�� 45�б��� // �� 3���� �Ϸ�
7:00 ~ 8:15 ��԰�� 9:20 ~ 35  45��..
��� ��������
���缭 �̱��� / �ȸ��߰� �Ѿ ���
�׷��� ���� ������ ��� ���� ����
����ġ�� ���� ���� ���� +1 �̰ų� / 0�̰ų��� ����� �� 2����
*/