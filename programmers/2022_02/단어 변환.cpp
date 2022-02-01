#include <string>
#include <vector>

using namespace std;

bool vis[50]={0};
vector<string> w;
string t="";
int answer=500;

bool cmp(string a, string b){
    int check=0;
    for(int i=0; i<a.size(); i++){
        if (a[i] != b[i]) check++;
    }
    if(check==1) return true;
    return false;
}

void dfs(string s, int cnt){
    if(s == t){
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0; i<w.size(); i++){
        if(vis[i]) continue;
        if(cmp(s,w[i])){
            vis[i] = true;
            dfs(w[i], cnt+1);
            vis[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    t=target;
    w=words;
    
    dfs(begin, 0);
    if(answer == 500) answer=0;
    
    return answer;
}
//5Ка