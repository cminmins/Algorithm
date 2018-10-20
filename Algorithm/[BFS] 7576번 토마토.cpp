#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1, 0,-1,0 };
int v[1000][1000] = { 0, };
int d[1000][1000] = { 0, };

int main()
{
	int m, n;
	cin >> m >> n;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> v[i][j];
			if (v[i][j] == -1)
				d[i][j] = -1;
			else if (v[i][j] == 1)
			{
				q.push(make_pair(i, j));
				d[i][j] = 1;
			}
		}
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first; q.pop();
		for (int k = 0; k < 4; k++)
		{
			int ddx = x + dx[k];
			int ddy = y + dy[k];
			if (ddx >= 0 && ddx < m && ddy >= 0 && ddy < n && v[ddy][ddx] == 0 && d[ddy][ddx] == 0)
			{
				q.push(make_pair(ddy, ddx));
				d[ddy][ddx] = d[y][x] + 1;
			}
		}
	}
	

	int max = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (d[i][j] > max)
				max = d[i][j];
			else if (d[i][j] == 0)
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << max - 1;
	return 0;
}