#include <bits/stdc++.h>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int ans = 0;
    sort(rocks.begin(), rocks.end());
    
    int s=0, e=distance, m;
    
    while(s<e){
        m=(s+e)/2;
        
        int cnt=0, temp=0;
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i]-temp < m) cnt++;
            else temp = rocks[i];
        }
        
        if(distance-temp < m) cnt++;
        
        cout << s << " " << m << " " << e << " " << cnt << endl;
        
        if(cnt<=n){             // cnt가 없앨 바위의 개수n 보다 작거나 같고
            if(ans < m) ans=m;  // 현재 답보다 m이 큰 경우가 답 (n개가 아닌 그 이하밖에 제거가 안되는 경우의 수 고려)
            s=m+1;
        }
        else{
            e=m;
        }
        
    }
    
    return ans;
}
/*
0  2 11 14 17 21 25
 2  9  3  3  4  4
m = 거리의 최솟값
만약 3이라면 3보다 작은놈은 그 돌을 없애고 카운트해야함
0  11  14  17  21 25 
 11
 cnt가 2보다 작으니 s를 증가
 
*/