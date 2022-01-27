#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> enr, vector<string> ref, vector<string> sel, vector<int> amo) {
    vector<int> ans;
    map<string, int> res;
    map<string, string> p;
    
    for(int i=0; i<enr.size(); i++){
        p[enr[i]]=ref[i];
    }
    
    for(int i=0; i<sel.size(); i++){
        string seller = sel[i];
        int amount = amo[i]*100;        //1200
        int ten = amount/10;            //120
        
        res[seller] += amount - ten;    //1080
                                        //cout << seller << " " << amount << " " << ten << endl;
        while(seller != "-" && amount >= 10){   // or 돈이 0이 될때까지?
                                        //cout << p[seller] << endl;
            seller = p[seller];
            amount = ten;               //120
            ten = amount/10;            //12
            
            res[seller] += amount - ten;//108
                                        //cout << seller << " " << amount << " " << ten << " "<< endl;
        }
    }
    
    for(auto a : enr) ans.push_back(res[a]);
    
    return ans;
}
/*12:00 ~ 52

*/