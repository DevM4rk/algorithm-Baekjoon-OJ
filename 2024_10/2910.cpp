#include <bits/stdc++.h>

using namespace std;

unordered_map<int,pair<int,int>> m;
int cnt,arr[1001];

int main(){
    int n,c; cin >> n >> c;
    for(int i=0; i<n; i++){
        int t; cin >> t;
        arr[i]=t;
        if(!m.count(t)){
            m[t] = {0,cnt};
            cnt++;
        }
        else{
            m[t].first++;
        }
    }

    sort(arr,arr+n,[](const int &a, const int &b){
        if(m[a].first == m[b].first){
            return m[a].second < m[b].second;
        }
        return m[a].first > m[b].first;
    });

    for(int i=0; i<n; i++) cout << arr[i] <<  " ";
}
/*
입력받으면서 
map에 카운트
cmp로 맵에 비교하면서, 근데 같다면 먼저입력된순
그것도 map에 담으면됨
*/