#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Time {
    int start;
    int finish;
};

bool cmp(Time i, Time j){
    if(i.finish == j.finish) 
        return i.start < j.start;
    else 
        return i.finish < j.finish;
}

int main(){
    int N;
    cin >> N;
    
    vector<Time> T(N);
    for (int i = 0; i < N; i++){
        cin >> T[i].start >> T[i].finish;
    }

    sort(T.begin(), T.end(), cmp);

    int cnt=0;
    int temp=0;

    for (int i = 0; i < N; i++){
        if(T[i].start < temp) continue;
        temp = T[i].finish;
        cnt++;
    }
    
    cout << cnt << endl;
}