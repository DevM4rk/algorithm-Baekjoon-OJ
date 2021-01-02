#include <iostream>
#include <queue>

using namespace std;

int N,temp;
priority_queue<int,vector<int>,greater<int>> pq_min;
priority_queue<int> pq_max;

void solve(){
<<<<<<< HEAD:2021_01/1655.cpp
    if( pq_max.top() > temp ){ //입력값이 중간값보다 작을 경우
=======
    if( pq_max.top() > temp ){
>>>>>>> 0d2883ac4c0c91b5e8489beb1bbc448595292b47:2020_12/1655.cpp
        pq_max.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 0 ){
            pq_min.push( pq_max.top() );
            pq_max.pop();
        }
    } 
    else{   //입력값이 중간값보다 클 경우
        pq_min.push(temp);

        if( (pq_max.size() + pq_min.size()) % 2 == 1 ){
            pq_max.push( pq_min.top() );
            pq_min.pop();
        }
    }

    cout << pq_max.top() << "\n";
}

/*
기준(max.top)보다 작거나 같으면 max 크면 min로 분류

2 4 6  (1,3,5,7)
짝수일때 작게 분류 된 경우 max top , min push, max pop
2 4 6 8 (1,3,5,7,9)
홀수일때 크게 분류 된 경우 min top 을 max push 후 min pop 해서 기준이되게
가 아니라 
사이즈에 따라서 나눠야하나
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