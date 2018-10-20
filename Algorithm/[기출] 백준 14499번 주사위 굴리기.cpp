#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };
int N, M;
int m[21][21];
int dice[4][3];
vector<int> dir;


int daegul(int y, int x, int d)
{
	if (y >= N || y < 0 || x >= M || x < 0)
		return -1;

	// 위로 구르기
	if (d == 3)
	{
		int temp = dice[0][1];
		dice[0][1] = dice[1][1]; dice[1][1] = dice[2][1]; 
		dice[2][1] = dice[3][1]; dice[3][1] = temp;
	}
	// 아래로 구르기
	else if (d == 4)
	{
		int temp = dice[3][1];
		dice[3][1] = dice[2][1]; dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1]; dice[0][1] = temp;
	}
	// 오른쪽으로 구르기
	else if (d == 2)
	{
		int temp = dice[1][0];
		dice[1][0] = dice[1][1]; dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1]; dice[3][1] = temp;
	}
	// 왼쪽으로 구르기
	else if (d == 1)
	{
		int temp = dice[1][2];
		dice[1][2] = dice[1][1]; dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1]; dice[3][1] = temp;
	}


	if (m[y][x] == 0)
		m[y][x] = dice[3][1];
	else if (m[y][x] != 0)
	{
		dice[3][1] = m[y][x];
		m[y][x] = 0;
	}
	return dice[1][1];
}

int main()
{
	int x, y, k;
	cin >> N >> M >> y >> x >> k;
	for (int ddy = 0; ddy < N; ddy++)
		for (int ddx = 0; ddx < M; ddx++)
			cin >> m[ddy][ddx];


	for (int i = 0; i < k; i++)
	{
		int temp;
		// 구르기
		cin >> temp;
		y += dy[temp]; x += dx[temp];
		int ans = daegul(y, x, temp);
		if (ans != -1)
			cout << ans << endl;
		else if(ans == -1)
		{
			y -= dy[temp]; x -= dx[temp];
		}
	}
	return 0;
}