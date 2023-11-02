#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, pair<int,int>, pair<int,int>>> v;
pair<int,int> parent[1001][1001];
vector<pair<int,int>> fj;

int n,c,sum,num;

pair<int,int> find(pair<int,int> node){
    auto [x,y] = node;
    if(parent[x][y] == node) return {x,y};

    parent[x][y] = find(parent[x][y]);
    return parent[x][y];
}

int main(){
    cin >> n >> c;

    for(int i=0; i<=1000; i++){
        for(int j=0; j<=1000; j++){
            parent[i][j] = {i,j};
        }
    }

    for(int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        fj.push_back({a,b});
    }

    for(int i=0; i< fj.size(); i++){
        for(int j=i+1; j< fj.size(); j++){
            auto [x,y] = fj[i];
            auto [x1,y1] = fj[j];
            int num = (x-x1)*(x-x1) + (y-y1)*(y-y1);

            v.push_back({num, {x,y}, {x1,y1}});
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        auto [value, a, b] = v[i];

        if(value < c) continue;

        a = find(a);
        b = find(b);

        if(a == b) continue;

        parent[a.first][a.second] = b;
        sum += value;
        num++;

        if(num >= n-1){
            break;
        }
    }

    bool fail = false;
    auto a = find(fj[0]);
    for(auto f : fj){
        if(find(f) != a ) fail = true;
    }

    if(sum==0 || fail) cout << -1;
    else cout << sum;
}