#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> sticker)
{
    int n = sticker.size();
    int dp[100001][2];
    
    dp[0][0] = dp[1][0] = sticker[0];   //��
    dp[0][1] = 0;
    dp[1][1] = sticker[1];
    
    for(int i=2; i<n; i++){
        if(i != n-1){
            dp[i][0] = max(dp[i-2][0]+sticker[i], dp[i-1][0]);        
        }
        dp[i][1] = max(dp[i-2][1]+sticker[i], dp[i-1][1]);        
    }
    
    if(n == 1) return sticker[0];
    return max(dp[n-2][0], dp[n-1][1]);
}
// ù ��° ��ƼĿ�� ���� ���, ���� ���� ��� �ΰ����� dp
// �� ���� ���� ū ���� ������ dp