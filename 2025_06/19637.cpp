#include <bits/stdc++.h>

using namespace std;

map<int,string> power;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n,m; cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; int a;
        cin >> s >> a;
        
        if(!power.count(a)){
            power[a] = s;
            v.push_back(a);
        }
    }

    for(int i=0; i<m; i++){
        int num; cin >> num;

        int st = 0, end = v.size() - 1;
        while(st<=end){
        int mid = (end+st)/2;
            // cout << st  << " " << mid << " " << end << " " << v[mid] << " " << num << " ";
            
            if(v[mid] < num){
                st = mid+1;
                // cout << 1 << endl;
            }
            else{
                end = mid-1;
                // cout << 2 << endl;
            }
        }
        
        cout << power[v[st]] << "\n";
    }

}

/*
v[0] = 10000;
map[10000] = WEAK;
*/