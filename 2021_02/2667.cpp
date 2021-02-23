#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

#define MAX 25

int N;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int cnt;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector <int> vec;

void DFS(int x, int y) {
	cnt++;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (arr[nx][ny] == 1 && visited[nx][ny] == false){
			DFS(nx, ny);
		}
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; j++)	arr[i][j] = temp[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				DFS(i, j);
				vec.push_back(cnt);
			}
		}
	}

	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;

	return 0;
}

/*
�Է°��� �迭�� �ް� 

1�϶��� �湮���Ѱ��� üũ
DFS�� �ѱ�

DFS - 
�湮üũ,
�����¿쿡 1�̰ų� �湮�� ���Ѱ�� DFS�� �ѱ�

*/