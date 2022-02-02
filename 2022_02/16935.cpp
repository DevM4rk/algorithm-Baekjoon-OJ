#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n, m, r;
int a[100][100];
int temp[100][100];
void one()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			temp[i][j] = a[n - 1 - i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];
}
void two()
{
	memset(temp, 0, sizeof(temp));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			temp[i][j] = a[i][m - 1 - j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];
}
void three()
{
	memset(temp, 0, sizeof(temp));

	int h = n;

	swap(n, m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			temp[i][j] = a[h - 1 - j][i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];
}
void four()
{
	memset(temp, 0, sizeof(temp));

	int w = m;

	swap(n, m);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			temp[i][j] = a[j][w-1-i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];
}
void five()
{
	memset(temp, 0, sizeof(temp));

	int N = n / 2;
	int M = m / 2;

	for(int i=0; i<N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i][j+M] = a[i][j];
		}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i+N][j + M] = a[i][j+M];
		}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i+N][j] = a[i+N][j+M];
		}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i][j] = a[i+N][j];
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];

}
void six()
{
	memset(temp, 0, sizeof(temp));

	int N = n / 2;
	int M = m / 2;

	//4번을 3번으로
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i + N][j + M] = a[i + N][j];
		}
	// 3번을 2번으로
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i][j + M] = a[i + N][j + M];
		}
	// 1번을 4번으로
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i + N][j] = a[i][j];
		}
	
	//2번을 1번으로
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			temp[i][j] = a[i][j+M];
		}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = temp[i][j];

}
int main()
{
	bool w = false, h = false;
	cin >> n >> m >> r;
	if (n <= m)
		w = true;
	for(int i=0; i<n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}

	for (int i = 0; i < r; ++i)
	{
		int num;
		cin >> num;
		if (num == 1)
			one();
		else if (num == 2)
			two();
		else if (num == 3)
			three();
		else if (num == 4)
			four();
		else if (num == 5)
			five();
		else if (num == 6)
			six();
		
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}