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
���� �Է� �����鼭
���� üũ cnt++
5��°�� �� psh
6���� ���� ���� üũmap

6���ƴ��� �Ÿ��鼭 ���� �ٽ� ���鼭 �հ� ���
�迭�� ���� ���������,,
������ ���ٸ� ��� üũ, �������ϼ�������
������ ���ٸ� 5���迭�� ���廡������ ��

*/