#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int n, ans;
int player[51][10], order[10];
bool vis[10];

void play(){
    int hitter=1, score=0;

    for(int i=1; i<=n; i++){
        int outcnt=0, pos[4]={0,};

        while(true){
            int hit = player[i][order[hitter]];
            hitter++;
            if(hitter==10) hitter = 1;

            if(hit==0){
                outcnt++;
                if(outcnt==3) break;
            }
            else{
                for(int j=3; j>=0; j--){
                    if(pos[j]==0 && j!=0) continue;
                    pos[j]=0;

                    if(j + hit >= 4)
                        score++;
                    else
                        pos[j+hit]=1;
                }
            }
        }
    }

    ans = max(ans, score);
}

void dfs(int x){
    if(x==10){
        play();
        return;
    }

    for(int i=2; i<=9; i++){
        if(vis[i]) continue;
        vis[i] = true;
        order[x]=i;
        if(x==3) dfs(x+2);
        else dfs(x+1);
        vis[i] = false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=9; j++){
            cin >> player[i][j];
        }
    }

    vis[1]=true;            // 1번 선수는 무조건 4번 타석
    order[4]=1;

    dfs(1);

    cout << ans;
}