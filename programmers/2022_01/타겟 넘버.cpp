#include <bits/stdc++.h>

using namespace std;

int n, answer, target;
vector<int> num;

void dfs(int sum, int cnt){
    if(cnt == n){
        if(sum == target) answer++;
        return;
    }
    
    dfs(sum+num[cnt], cnt+1);
    dfs(sum-num[cnt], cnt+1);
    
}

int solution(vector<int> numbers, int t) {
    answer = 0;
    num = numbers;
    target = t;
    n = numbers.size();

    dfs(0,0);
    
    return answer;
}
//1ºĞÄÆ