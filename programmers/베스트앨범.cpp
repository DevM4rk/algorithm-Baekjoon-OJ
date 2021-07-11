#include <bits/stdc++.h>

using namespace std;

typedef pair<string, int> si;
typedef pair<int, int> ii;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> m;
    
    for(int i=0; i<genres.size(); i++)
        m[genres[i]] += plays[i];
    
    vector<si> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), [](si a, si b) {
		return a.second > b.second;
		});
    
    for (si it : v){
        string kind = it.first;
        vector<pair<int,int>> idx;
        
        for(int i=0; i<genres.size(); i++){
            if( genres[i] == kind ){
                idx.push_back({plays[i],i});
            }
        }
        
        sort(idx.begin(), idx.end(), [](ii a, ii b) {
		    return a.first > b.first;
		});
        
        for(int i=0; i<idx.size(); i++){
            if(i==2) break;
            
            answer.push_back(idx[i].second);
        }
    }
    
    /*
    곡의 장르대로 map에 추가             장르, idx, plays
    가장 재생 많이 된 장르 순서대로 저장  pop , 4, 2500 으로 저장 할 순 없을까
    그 중에서 또 가장 재생 많이 된 2개를 뽑아야 됨
    */
    
    return answer;
}