#include <bits/stdc++.h>

using namespace std;

vector<string> v,fv;

    int ans;
    vector<string> fd;

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        string str; cin >> str;
        v.push_back(str);
    }
    fv=v;
    sort(v.begin(), v.end());

    for(int i=0; i<n-1; i++){
        string s1 = v[i] , s2 = v[i+1];
        if(s1 == s2) continue;
        int size = min(s1.size(), s2.size());
        int cnt=0;
        string str="";
        for(int j=0; j<size; j++){
            if(s1[j] != s2[j]) break;
            cnt++;
            str.push_back(s1[j]);
        }

        if(cnt > ans){
            ans = cnt;
            fd.clear();
            fd.push_back(str);
        }
        else if(cnt == ans && cnt>0){
            fd.push_back(str);
        }
    }

    int cnt=0;
    string ss="";
    for(auto str : fv){
        if(cnt==0){
            for(auto f : fd){
                if(str.find(f,0) != string::npos) {
                    cout << str << endl;
                    cnt++;
                    ss=f;
                    break;
                }
            }
        }
        else{
            if(str.find(ss) != string::npos){
                cout << str;
                break;
            }

        }
    }

    
}
/*
입력되는 순서대로 제일 앞! 
반례테스트하기
*/