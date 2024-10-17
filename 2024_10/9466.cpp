#include <bits/stdc++.h>

using namespace std;

int n,st;
int arr[100002];
int vis[100002];
vector<int> save;

void dfs(int x){
    if(vis[x]==3 && x == st){
        // cout<< "true" << endl;
        for(auto a : save) vis[a] = 1;
        return;
    }
    if(vis[x]==3){ 
        for(auto a : save) vis[a] = 0;
        vis[st] = -1;
        return;
    }
    if(vis[x]==-1){
        for(auto a : save) vis[a] = -1;
        return;
    }
    if(vis[x]==1){
        for(auto a : save) vis[a] = -1;
        vis[x]=1;
        return;
    }
    
            // if(check==1){
            //     for(auto a : save) vis[a] = 1;

            // }
            // else if(check==2){
            //     for(auto a : save) vis[a] = 0;
            //     vis[i] = -1;
            // }
            // else {
            //     for(auto a : save) vis[a] = -1;
            // }

    // cout << x << " " ;
    //     for(int i=1; i<=n; i++){
    //         cout << vis[i] << " ";
    //         }
    //         cout << endl;

    vis[x] = 3;
    save.push_back(x);
    dfs(arr[x]);
    return;
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> arr[i];
            if(i==arr[i]) vis[i] = 1;
        }

        for(int i=1; i<=n; i++){
            
            if(vis[i]==1 || vis[i]==-1) continue;
            st = i;
            dfs(i);

            save.clear();
        }


        int cnt=0; 
        for(int i=1; i<=n; i++){
            if(vis[i]!=1) cnt++;
        }
        cout << cnt << endl;

        fill(vis, vis+n+2, 0);
    }
}
/*
시작점 정해두고 시작점으로 돌아오면 1

*/