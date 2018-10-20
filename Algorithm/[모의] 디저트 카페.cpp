#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[4] = { -1, 1, 1, -1 };
int dx[4] = { 1, 1, -1, -1 };
bool dir[4];
int N;
bool disert[101];
bool v[21][21];
int m[21][21];

bool check_dir(int y, int x)
{
	return y >= 0 && y < N && x >= 0 && x < N;
}


int ans = 0;
void dfs(int sy, int sx, int y, int x, int cnt, int d)
{
	if (cnt > 1 && sy == y && sx == x)
	{
		ans = max(ans, cnt);
		return;
	}

	for (int i = d; i < 4; i++)
	{
		if (i == (4 + d + 2) % 4)
			continue;

		int ddy = y; int ddx = x;
		// 갈수있는 곳이고, 지금 선과 연결되어있는지 확인
		while (check_dir(ddy + dy[i], ddx + dx[i]) && v[ddy][ddx] == true)
		{
			ddy += dy[i]; ddx += dx[i];
			// 안먹어본 디저트 일때만 실행
			if (!disert[m[ddy][ddx]])
			{
				disert[m[ddy][ddx]] = true;
				v[ddy][ddx] = true;
				dfs(sy, sx, ddy, ddx, cnt + 1, i);
				disert[m[ddy][ddx]] = false;
				v[ddy][ddx] = false;
			}
			// 4방향 다 돌고 다음 목적지가 출발점일때
			if(sy == ddy && sx == ddx)
				dfs(sy, sx, ddy, ddx, cnt, i);
		}
	}
}

int main()
{
	int test;
	cin >> test;
	for (int i = 1; i <= test; i++)
	{
		cin >> N;
		ans = -1;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> m[y][x];

		for (int y = 1; y < N; y++)
			for (int x = 0; x < N; x++)
			{
				v[y][x] = true;
				disert[m[y][x]] = true;
				dfs(y, x, y, x, 1, 0);
				disert[m[y][x]] = false;
				v[y][x] = false;
			}

		cout << "#" << i << " " << ans << endl;
	}

	return 0;
}