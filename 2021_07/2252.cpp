//위상정렬
//방향 그래프에 존재하는 각 정점들의 선행 순서를 위배하지 않으면서 모든 정점을 나열하는 것
//사이클 x
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#define MAX_N 32000
using namespace std;
vector<vector<int>> vt;
stack<int> st;
int n, m, x, y, visited[MAX_N + 1];
void dfs(int v) {
    visited[v] = true;
    for (auto i : vt[v]) {
        if (visited[i])
            continue;
        dfs(i);
    }
    st.push(v);
}
int main() {
    scanf("%d%d", &n, &m);
    vt.resize(n + 1);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &x, &y);
        vt[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }
    while (st.size()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
//2252