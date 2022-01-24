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

string str, temp;
bool tag;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    getline(cin, str);

    for(int i=0; i<str.size(); i++){
        char s = str[i];

        if(s == '<'){
            if(temp.size()){
                reverse(all(temp));
                cout << temp;
                temp.clear();
            }
            tag = true;
            temp += s;
        }
        else if(s =='>'){
            tag = false;
            temp += s;
            cout << temp;
            temp.clear();
        }
        else if(s == ' '){
            if(tag){
                temp += s;
            }
            else{
                reverse(all(temp));
                temp += s;
                cout << temp;
                temp.clear();
            }
        }
        else{
            temp += s;
            if(i==str.size()-1){
                reverse(all(temp));
                cout << temp;
            }
        }
    }
}