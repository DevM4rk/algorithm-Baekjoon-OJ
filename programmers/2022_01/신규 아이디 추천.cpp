#include <bits/stdc++.h>

using namespace std;

bool need(string id, int i){
    return (id[i] >= 'a' && id[i] <= 'z') || 
        (id[i] >= '0' && id[i] <= '9') || 
        id[i] == '-' || id[i] == '_' || id[i] == '.';
}

string solution(string id) {

    cout << id << endl;

    //1,2단계
    for(int i=0; i<id.size(); i++){
        if(id[i] >= 'A' && id[i] <= 'Z') id[i] = id[i] + ('a'-'A'); // 1
        else if( !(need(id, i)) ){    //2
            id.erase(id.begin()+i);
            i--;
        }
    }
    
    cout << id << endl;

/*  3
    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }
*/
    //3
    int cnt=0;
    for(int i=0; i<id.size(); i++){
        if(id[i] == '.'){
            cnt++;
        }
        
        if(id[i] != '.' || i == id.size()-1){
            if(cnt==1) cnt=0;
            else if(cnt>=2){
                id.erase(id.begin()+i-cnt+1, id.begin()+i);
                i -= cnt-1;
                cnt=0;
            }
        }
    }
    cout << id << endl;
    
    //4
    if(id[0] == '.') id.erase(id.begin());  //front
    if(id[id.size()-1] == '.') id.erase(id.end()-1); // back, pop_back
    
    cout << id << endl;
    
    //5
    if(id.empty()) id += 'a';
    
    cout << id << endl;
    
    //6
    if(id.size() >= 16) id.erase(id.begin()+15, id.end());
    if(id[id.size()-1] == '.') id.erase(id.end()-1);

    cout << id << endl;
    
    //7
    while(id.size() <= 2) id += id[id.size()-1];

    cout << id << endl;

    return id;
}
/*5시간짜리 11시까지
5:53 시작 ~ 6:37 클.. 문자열에 약하다
*/