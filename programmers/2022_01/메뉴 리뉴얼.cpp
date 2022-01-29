#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> m;
string ord; 
int k;

void dfs(string s, int idx){
    if(s.size() == k){
        m[s]++;
        return;
    }
    
    for(int i=idx; i<ord.size(); i++){
        s+=ord[i];
        dfs(s, i+1);
        s.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> ans;
    sort(orders.begin(), orders.end());
        
    for(int i=0; i<orders.size(); i++){
        for(int j=0; j<course.size(); j++){
            ord = orders[i]; k = course[j];
            sort(ord.begin(), ord.end());
            
            dfs("", 0);
        }
    }
    
    //for(auto [a,b] : m) if(a.size()==2) cout << a << " " << b << endl;
    
    //map k로 나누고 key순으로 정렬해야댐
    for(int i=0; i<course.size(); i++){
        k = course[i];
        vector<pair<int, string>> v;
    
        for(auto [key,val] : m) if(key.size()==k) v.push_back({val,key});
        sort(v.begin(), v.end(), greater());
        
        int cost=v[0].first;
        for(int j=0; j<v.size(); j++){
            if(cost <= 1) continue;
            cout << v[j].second << " "<< v[j].first << endl;
            if(v[j].first == cost) ans.push_back(v[j].second);
            else break;
        }
        
    }
    sort(ans.begin(), ans.end());
    return ans;
}
/*11시까지
6:39 시작 ~ 7:34
*/