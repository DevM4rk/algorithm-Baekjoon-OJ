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
            diff +    �ٵ� -������
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

2ĭ���̴� �߰��� �� - (��-��/2) ���� �̸��� �ǹ��̾����
3ĭ���̴� �� - (��-��/3) , �� - 2*(��-��/3) ���� �̸� �ǹ��̾����
�߰��� �ɸ��°� �ϳ��������� �ȵ�
�Ҽ��� �����
*/