#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int K, V, E;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> K;

    while (K--)
    {
        cin >> V >> E;

        vi v[V+1];
        int visited[V+1] = {0}; // 0 = none / distinguish by 1,2
        bool check = true;

        while (E--)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int j = 1; j <= V; j++)
        {
            if(visited[j] == 0)
            {
                
        queue<int> q;
        q.push(j);

        visited[j] = 1;

        while (!q.empty())
        {
            int x = q.front();
            int dist = visited[x];
            q.pop();

            for (int i = 0; i < v[x].size(); i++)
            {

                // if( dist == visited[v[x][i]] ){
                //     cout << "NO" << endl;
                //     check = false;
                //     break;
                // }

                if (visited[v[x][i]] == 0)
                {
                    if (dist == 1)
                        visited[v[x][i]] = 2;
                    else if (dist == 2)
                        visited[v[x][i]] = 1;

                    q.push(v[x][i]);
                }
            }
        }
            }
        }
        
        for (int i = 1; i <= V; i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                // 인접한 정점끼리의 색이 같으면 이분그래프X
                if (visited[i] == visited[v[i][j]])
                {
                    check = false;
                }
            }
        }

        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
