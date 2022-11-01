#include <bits/stdc++.h>

using namespace std;

int answer,n,m,maxi,mc,maxcnt,teststart;
vector<int> key,test;
set<string> s;
vector<vector<string>> relation;

void dfs(int cnt,int x, int idx){
    if(cnt == x){

        cout << x << " ";
        for(auto k:key) cout << k;
        cout << endl;
        
        s.clear();
        string str = "";
        for(int i=0; i<n; i++){
            str.clear();
            for(int j=teststart; j<test.size(); j++){
                str += relation[i][test[j]];
            }
            if(s.count(str)){
                return;
            }
            s.insert(str);
        }
        mc++;
        int c=0;
        for(auto &k : key) if(k==0) c++;
        if(c < x){
            cout << mc << endl;
            maxcnt = max(maxcnt, mc);
            mc--;
            teststart = max(0, teststart-x);
            return;
        }
        
        cnt=0;
        teststart+=x;
    }
    
    for(int i=idx; i<m; i++){
        if(!key[i]){
            key[i] = 1;
            test.push_back(i);
            
            dfs(cnt+1, x, i+1);
            
            key[i] = 0;
            test.pop_back();
        }
    }
}

int solution(vector<vector<string>> rel) {
    relation = rel;
    n = relation.size();
    m = relation[0].size();
    
    for(int i=0; i<m; i++){
        int check=1;
        s.clear();
        for(int j=0 ;j<n; j++){
            string str = relation[j][i];
            if(s.count(str)){
                check=0;
                break;
            }
            s.insert(str);
        }
        key.push_back(check);
        if(check) answer++;
    }

    for(int i=2; i<=m-answer; i++){
        dfs(0, i, 0);
        maxi = max(maxi, maxcnt);
        teststart=0;
        mc=0;
    }
    
    return answer+maxi;
}