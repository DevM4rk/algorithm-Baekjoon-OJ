#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) 
{
    vector<int> answer;
    int board[101][101];
    int m = rows, n = columns;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
        board[i][j] = (i - 1)*n + j;

    for (auto vec : queries)
    {
        int x1 = vec[0];
        int y1 = vec[1];
        int x2 = vec[2];
        int y2 = vec[3];

        int temp = board[x1][y1];
        int result = temp;
        for (int i = x1; i < x2; i++)
        {
            board[i][y1] = board[i + 1][y1];
            result = min(result, board[i][y1]);
        }
        for (int j = y1; j < y2; j++)
        {
            board[x2][j] = board[x2][j + 1];
            result = min(result, board[x2][j]);
        }
        for (int i = x2; i>x1; i--)
        {
            board[i][y2] = board[i - 1][y2];
            result = min(result, board[i][y2]);
        }
        for (int j = y2; j > y1; j--)
        {
            board[x1][j] = board[x1][j - 1];
            result = min(result, board[x1][j]);
        }
        board[x1][y1 + 1] = temp;

        answer.push_back(result);
    }

    return answer;
}

// 반대로 돌면 편한 것을 왜 생각을 못했을까