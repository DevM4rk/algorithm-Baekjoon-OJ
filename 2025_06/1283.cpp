#include <bits/stdc++.h>

using namespace std;

set<char> m;

int main(){
    int n; cin >> n;
    cin.ignore();
    vector<string> v(5);
    for(int i=0; i<n; i++){
        string s; 
        getline(cin, s);
        stringstream stream;
        stream.clear();
        stream.str(s);
        bool suc =false;
        v = vector<string> (5);

        int k=0;
        for(auto &a : v){
            stream >> a;
            if(a == "") break;
            k++;
        }

        int cnt = -1;
        for(auto a : v){
            cnt++;
            char c = a[0];
            char cc;
            if (isupper(c)){
                cc = c+32;
            }
            else{
                cc = c-32;
            }

            if((m.count(c) != 1 && m.count(cc) != 1) && c != 0){
                m.insert(c);

                v[cnt].insert(v[cnt].begin()+1, ']');
                v[cnt].insert(v[cnt].begin(), '[');
                //v[cnt][0] ¿©±â ÁÂ¿ì °¨½Î±â

                for(int j=0; j<k; j++){
                    cout << v[j] << " ";
                }
                cout << endl;
                suc = true;
                break;
            }
        }
        if(suc == false){
            int cntt=0; 
            int temp=-1;
            for(auto c : s){
                cntt++;
                if(c == ' ') {
                    cout << ' ';
                    continue;
                }

                char cc;
                if (isupper(c)){
                    cc = c+32;
                }
                else{
                    cc = c-32;
                }
                
                if(suc == false){
                    if((m.count(c) != 1 && m.count(cc) != 1)){
                        m.insert(c);
                        suc = true;
                        temp = cntt;
                        cout << '[' << c << ']';

                    }   
                }

                if(temp != cntt) cout << c;

            }
            cout << endl;
        }
    }
}