#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binary(int m, int k, vector<int> stones){
    
    int cnt=0;
    for(int i=0; i<stones.size(); i++){
        if( stones[i] <= m )
            cnt++;
        else 
            cnt=0;
        
        if( cnt == k ) return true;
    }
    
    return false;
}

int solution(vector<int> stones, int k) {
    int s = 1;
    int e = *max_element(stones.begin(), stones.end());
    
    while(s < e){
        int m = (s+e)/2;

        if(binary(m,k,stones))
            e = m;
        else        
            s = m+1;
    }
    
    return e;
}