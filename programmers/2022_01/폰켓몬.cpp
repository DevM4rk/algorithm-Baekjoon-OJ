#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int n = nums.size()/2;
    
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    if(nums.size() >= n) answer = n;
    else answer = nums.size();
    
    return answer;
}
/*3�ð�
7:00~5
*/