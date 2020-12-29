#include <iostream>
#include <deque>
#include <queue>

using namespace std;

deque<int> dq; // 1 ~ 10
queue<int> q;  // 뽑아내려는 수
int N, M, temp, sum = 0, dq_temp;

void solve()
{
    while (q.size() != 0)
    {
        temp = q.front();
        q.pop();

        if (temp != dq.front())
        {
            int le = 0, ri = 0;
            while (dq.at(le++) != temp);
            le--;
            
            ri = dq.size() - le;
            if (le >= ri)
            {
                sum += ri;
                while (ri--)
                {
                    dq_temp = dq.back();
                    dq.pop_back();
                    dq.push_front(dq_temp);
                }
            }
            else
            {
                sum += le;
                while (le--)
                {
                    dq_temp = dq.front();
                    dq.pop_front();
                    dq.push_back(dq_temp);
                }
            }
        }

        dq.pop_front();
    }

    cout << sum << endl;
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        dq.push_back(i);

    while (M--)
    {
        cin >> temp;
        q.push(temp);
    }

    solve();
}