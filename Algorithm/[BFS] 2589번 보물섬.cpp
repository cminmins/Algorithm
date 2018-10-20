#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char m[50][50];
bool v[50][50];
int d[50][50];

int main()
{
	int a, b;
	cin >> a >> b;
	queue<pair<int, int>> q;
	for (int y = 0; y < a; y++)
		for (int x = 0; x < b; x++)
			cin >> m[y][x];
	

	int max = 0;
	for (int y = 0; y < a; y++)
	{
		for (int x = 0; x < b; x++)
		{
			if (m[y][x] == 'L')
			{
				v[y][x] = true;
				d[y][x] = 0;
				q.push(make_pair(y, x));
				while (!q.empty())
				{
					int sy = q.front().first; int sx = q.front().second; q.pop();
					for (int i = 0; i < 4; i++)
					{
						int ddy = sy + dy[i]; int ddx = sx + dx[i];
						if (m[ddy][ddx] == 'L' && v[ddy][ddx] == false && ddy >= 0 && ddy < a && ddx >= 0 && ddx < b)
						{
							v[ddy][ddx] = true;
							d[ddy][ddx] = d[sy][sx] + 1;
							q.push(make_pair(ddy, ddx));
							if (max < d[ddy][ddx])
								max = d[ddy][ddx];
						}
					}
				}
			}
			memset(v, 0, sizeof(v));
			memset(d, 0, sizeof(d));
		}
	}
		

	cout << max;
	return 0;
}