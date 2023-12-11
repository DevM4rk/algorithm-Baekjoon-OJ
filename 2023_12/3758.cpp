#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k,t,m;
        cin >> n >> k >> t >> m;

        int mm = m;
        vector<vector<int>> v(n+1, vector<int>(k+1));
        vector<int> cnt(n+1);
        vector<int> sum(n+1);
        vector<int> num(m+1);
        int rank=1;

        while(m--){
            int i,j,s;
            cin >> i >> j >> s;
            if(v[i][j] < s) v[i][j] = s;
            cnt[i]++;
            num[m]=i;
        }

        for(int a=1; a<n+1; a++){
            for(int b=1; b<k+1; b++){
                sum[a]+= v[a][b];
            }
        }

        for(int a=1; a<n+1; a++){
            if(a==t) continue;
            if(sum[t] < sum[a]) rank++;
            else if(sum[t] == sum[a]){
                if(cnt[t] > cnt[a]){
                    rank++;
                }
                else if(cnt[t] == cnt[a]){
                    for(int b=0; b<mm; b++){
                        if(num[b] == t){
                            rank++;
                            break;
                        }
                        else if(num[b] == a){
                            break;
                        }
                    }
                }

            }
        }

        cout << rank << "\n";
    }
}