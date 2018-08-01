#include <iostream>
#include <queue>
using namespace std;
bool map[100][100];
bool visit[100][100];
int dist[100][100];
int num[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int y, int x, int n)
{
	if (visit[y][x] == false)
	{
		visit[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i]; int xx = x + dx[i];
			if (0 <= yy && yy < n && 0 <= xx && xx < n && map[yy][xx] == true && visit[yy][xx] == false)
			{
				num[yy][xx] = num[y][x];
				dfs(yy, xx, n);
			}
		}
	}
}



int main()
{

	int n;
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			num[y][x] = -1;
			dist[y][x] = -1;
		}

	int city = 1;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] == true && visit[y][x] == false)
			{
				num[y][x] = city++;
				dfs(y, x, n);
			}
		}

	queue<pair<int,int>> q;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			if (map[y][x] == true)
			{
				q.push(make_pair(y, x));
				dist[y][x] = 0;
			}


	while (!q.empty())
	{
		int y = q.front().first; int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i]; int xx = x + dx[i];
			if (0 <= yy && yy < n && 0 <= xx && xx < n && map[yy][xx] == false)
			{
				if (dist[yy][xx] == -1)
				{
					dist[yy][xx] = dist[y][x] + 1;
					num[yy][xx] = num[y][x];
					q.push(make_pair(yy, xx));
				}
			}
		}
	}

	int min = -1;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
		{
			for (int i = 0; i < 4; i++)
			{
				int yy = y + dy[i]; int xx = x + dx[i];
				if (0 <= yy && yy < n && 0 <= xx && xx < n && num[yy][xx] != num[y][x])
				{
					if (min == -1 || min > dist[yy][xx] + dist[y][x])
						min = dist[yy][xx] + dist[y][x];
				}

			}
		}


	cout << min;
	return 0;
}