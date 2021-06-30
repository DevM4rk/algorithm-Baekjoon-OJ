#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, res;
int p[501][501];
int dp[501][501];

void dynamic() {
	dp[1][1] = p[1][1];
	res = dp[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + p[i][j];
			if (dp[i][j] > res) res = dp[i][j];
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= i; j++)
			cin >> p[i][j];

	dynamic();
	cout << res;
} //1932

/*
dp 풀이법

n번째까지 왔을 때의 최댓값 또는 최솟값을 점화식으로 나타내보자
*/
