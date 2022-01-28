#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> f, vector<string> r) {
    vector<int> answer;
    map<int,int> car;
    map<int,int> money;
    
    for(auto s : r){
        s[2] = ' '; // : -> 공백 치환
        stringstream stream;
        stream.str(s);
        int h, m, n; string check;
        stream >> h >> m >> n >> check;
        //cout << h << " " << m << " " << n << " " << check << endl;
        if(check == "IN"){
            car[n]= h*60 + m;
        }
        else{
            int temp = (h*60 + m) - car[n];
            car.erase(n);
            money[n]+= temp;
        }
    }
    for(auto a : car){
            int temp = 1439 - a.second;
            money[a.first]+= temp;
    }
    
    for(auto a : money){
        cout << a.first << " " << a.second << endl;
        int temp;
        if(a.second <= f[0]){
            temp = f[1];
        }
        else{
            int h = ((a.second - f[0]) + f[2]-1) / f[2];    //나눌 값을 더하고 -1 빼면 올림과 같은 효과
            temp = f[1] + h * f[3];
        }
        answer.push_back(temp);
    }
    
    return answer;
    
}
/**
9시 30분까지!
6:05 시작 ~ 52완료

24시 * 60 = 1440
23:59  =  1439
시간*60 + 분 을 해서 
*/