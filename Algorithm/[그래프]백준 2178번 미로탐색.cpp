#include <iostream>
#include <queue>
using namespace std; 
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
bool visit[100][100] = { 0 };
int dist[100][100] = { 0 };
bool map[100][100] = { 0 };
queue<pair<int, int>> q;

int main()
{
	int n, m;
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char temp = cin.get() - 48;
			map[i][j] = temp;
		}
		getchar();
	}
	dist[0][0] = 1;
	visit[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int y = q.front().first; int x = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i]; int xx = x + dx[i];
			if (0 <= yy && yy < n && 0 <= xx && xx < m)
				if (map[yy][xx] == true && visit[yy][xx] == false)
				{
					dist[yy][xx] = dist[y][x] + 1;
					visit[yy][xx] = true;
					q.push(make_pair(yy, xx));
				}
		}
	}
	cout << dist[n-1][m-1];
	return 0;
}