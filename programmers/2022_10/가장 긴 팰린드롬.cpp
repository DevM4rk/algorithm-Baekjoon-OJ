#include <iostream>
#include <string>
using namespace std;
int solution(string s)
{
    int answer=1;
    int n = s.size();
   
    for(int i=0; i<n; i++){
        //Ȧ
        int odd=1;
        int a=1;
        
        while(s[i-a] == s[i+a]){
            if(i-a < 0 || i+a > n) break;
            a++;
            odd+=2;
        }
        
        //¦
        int even=0;
        if(i+1 < n && s[i] == s[i+1]){
            even=2;
            int b=1;
            
            while(s[i-b] == s[i+1+b]){
                if(i-b < 0 || i+1+b > n) break;
                b++;
                even+=2;
            }
        }
        
        answer = max(answer, max(odd, even));
    }
    
    return answer;
}