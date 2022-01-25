#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;
int solution(vector<int> p, int limit) {
    int answer = 0;
    int s=0, e= p.size()-1;

    sort(all(p));
    
    while(s<=e){
        if(p[s]+p[e] > limit){
            e--;
        }
        else{
            s++;
            e--;
        }
        answer++;
    }
    
    return answer;
}

/*
정렬 후 2개 합하기
양쪽 두개의 포인터
100이면 바로 cnt ++ 
뒤에꺼랑 앞의 합이 100이 넘어버리면 뒤 포인터를 하나 앞당기고 cnt ++
100이하면 양 포인터를 하나씩 줄임

포인터가 같아지면 cnt ++ 하고 마무리
제일 작은거랑 젤 큰거 하면 끝임 다음 거 안 봐도 됨
*/