#include <iostream>
#include <queue>

using namespace std;

int N,temp;
priority_queue<int,vector<int>,greater<int>> pq_min;
priority_queue<int> pq_max;

void solve(){
<<<<<<< HEAD:2021_01/1655.cpp
    if( pq_max.top() > temp ){ //�Է°��� �߰������� ���� ���
=======
    if( pq_max.top() > temp ){
>>>>>>> 0d2883ac4c0c91b5e8489beb1bbc448595292b47:2020_12/1655.cpp
        pq_max.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 0 ){
            pq_min.push( pq_max.top() );
            pq_max.pop();
        }
    } 
    else{   //�Է°��� �߰������� Ŭ ���
        pq_min.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 1 ){
            pq_max.push( pq_min.top() );
            pq_min.pop();
        }
    }

    cout << pq_max.top() << "\n";
}

/*
����(max.top)���� �۰ų� ������ max ũ�� min�� �з�

2 4 6  (1,3,5,7)
¦���϶� �۰� �з� �� ��� max top , min push, max pop
2 4 6 8 (1,3,5,7,9)
Ȧ���϶� ũ�� �з� �� ��� min top �� max push �� min pop �ؼ� �����̵ǰ�
�� �ƴ϶� 
����� ���� �������ϳ�
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    cin >> temp;
    pq_max.push(temp);
    cout << temp << "\n";

    while(--N){
        cin >> temp;

        solve();
    }
    
}