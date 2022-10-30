#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    ll sum1=0, sum2=0;
    queue<ll> q1, q2;
    
    for(auto &a : queue1){
        q1.push(a);
        sum1+=a;
    }
    for(auto &a : queue2){
        q2.push(a);
        sum2+=a;
    }
    
    ll cnt=0;
    ll maxcnt=q1.size() + q2.size();
    
    while(cnt <= 2*maxcnt){
        if(sum1 == sum2){
            return cnt;
        }
        else if(sum1 < sum2){
            ll temp = q2.front(); q2.pop();
            q1.push(temp);
            sum2 -= temp;
            sum1 += temp;
        }
        else{
            ll temp = q1.front(); q1.pop();
            q2.push(temp);
            sum1 -= temp;
            sum2 += temp;
        }
        cnt++;
    }
    
    
    return -1;
}