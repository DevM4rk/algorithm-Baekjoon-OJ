#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<int> cnt(1001), five, input(1001), sum4(1001);
        map<int,int> team;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            input[i] = x;
            cnt[x]++;
            if(cnt[x] == 5){
                five.push_back(x);
            }
            else if(cnt[x] == 6){
                team[x]=0;
            }
        }

        int rank=1;
        for(int i=0; i<n; i++){
            if(team.count(input[i])){
                if(sum4[input[i]] < 4) team[input[i]] += rank;
                sum4[input[i]]++;
                rank++;
            }
        }
        
        vector<pair<int,int>> v(team.begin(), team.end());
        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
            return a.second < b.second;
        });

        // for(auto a : v) cout << a.first << " " << a.second << endl;

        set<int> fst;
        fst.insert(v[0].first);
        for(int i=1; i<v.size(); i++){
            if(v[0].second == v[i].second){
                fst.insert(v[i].first);
            }
            else{
                break;
            }
        }

        for(int i=0; i<five.size(); i++){
            if(fst.count(five[i])){
                cout<< five[i] << endl;
                break;
            }
        }

        
    }
}
/*
점수 입력 받으면서
팀들 체크 cnt++
5개째때 뱌열 psh
6개인 팀은 따로 체크map

6개아닌팀 거르면서 점수 다시 돌면서 합계 계산
배열로 빼고 점수순대로,,
점수가 같다면 계속 체크, 여러개일수있으니
점수가 같다면 5개배열중 가장빨리오는 순

*/