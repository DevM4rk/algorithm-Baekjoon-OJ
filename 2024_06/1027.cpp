#include <bits/stdc++.h>

using namespace std;

double bd[50];
int ans,num;

int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> bd[i];
    }

    for(int i=0; i<n; i++){
        int temp=0;
        for(int j=0; j<n; j++){
            // cout << i << " " << j << " " << temp << endl;
            if(i==j) continue;
            // if(i!=11) continue; // check delete plz
            if(abs(i-j)==1){
                temp++;
                continue;
            }

            float diff = (bd[i]-bd[j]) / (i-j);
            // cout << bd[i] << " " << bd[j] << " " << i-j << " " << diff << endl;

            bool check = true;
            /*
            1. i<j   bd[i]<bd[j]
            diff +          
            1. i<j   bd[i]>bd[j]
            diff -      
            1. i>j   bd[i]<bd[j]
            diff -          +
            1. i>j   bd[i]>bd[j]
            diff +    근데 -여야함
            */
           if(i<j){
                for(int k=1; k<abs(i-j); k++){
                    // cout << bd[i+k] << " " << bd[i] << " " << diff*k << endl;
                    if( bd[i+k] >= bd[i] + (diff*k) ){
                        check = false;
                        // cout << "its fail" << endl;
                        break;
                    }
                }
            }
            
           else if(i>j){
                diff *= -1;
                for(int k=1; k<abs(i-j); k++){
                    // cout << bd[i-k] << " " << bd[i] << " " << diff*k << endl;
                    if( bd[i-k] >= bd[i] + (diff*k) ){
                        check = false;
                        // cout << "its fail" << endl;
                        break;
                    }
                }
            }
            if(check) temp++;
        }

        if(ans <= temp){
            ans = temp;
            num = i;
            // cout << "reset \n";
        //     cout << ans << " " << i << " " << bd[i] << endl;
        }

    }
    cout << ans;
}
/*
1 5 3 2 6 3 2 6 4 2 5 7 3 1 5

                      1
        1     1       1
  1     1     1     1 1     1
  1     1     1 1   1 1     1
  1 1   1 1   1 1   1 1 1   1
  1 1 1 1 1 1 1 1 1 1 1 1   1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

2칸차이는 중간에 높 - (높-낮/2) 값의 미만의 건물이어야함
3칸차이는 높 - (높-낮/3) , 높 - 2*(높-낮/3) 값의 미만 건물이어야함
중간에 걸리는거 하나라도있으면 안됨
소수점 써야함
*/