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
7저장 후 temp 2
7저장 후 temp 5
당장의 temp만 비교할게아니라 그 사이에 큰 값이 오는 경우도 생각해야댐
스택 0 
v[0] < v[1] 이 경우가 나올 때 까지 반복
ans[0] = v[1];
스택 0 1
v[1] < v[2] = 2 라서 조건안됨 패스
스택 0 1 2
v[2] < v[3] 조건 만족
ans[2] = v[3];
s.pop();
v[1] < v[3] 조건 만족
ans[1] = v[3];

ans [5, 7 ,7]
이게 가능한 이유
스택의 역할 ans 에 입력 안된것을 체크하고 넘어감
작은 경우에는 넘어감
그 다음에는두가지경우가있음
5 2 6
5의 값보다 큰경우
그냥 흐름에 맞게 가면됨
5 2 4
5의 값보다 작은경우
스택에 남고 와일문 넘어감
그렇기 떄문에 -1 로 초기화를 해놔야함 모든 값을

54321일 경우
-1-1-1-1-1

*/