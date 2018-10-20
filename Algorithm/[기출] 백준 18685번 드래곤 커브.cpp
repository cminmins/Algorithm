#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool m[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void make_curve(int x, int y, int d, int g)
{
	vector<int> dir;
	m[y][x] = true;
	for (int i = 0; i <= g; i++)
	{
		if (dir.empty())
		{
			y += dy[d]; x += dx[d];
			m[y][x] = true;
			dir.push_back(d);
		}
		else
		{
			for (int k = dir.size() - 1; k >= 0; k--)
			{
				d = (dir[k] + 1) % 4; 
				y += dy[d]; x += dx[d]; 
				m[y][x] = true;
				dir.push_back(d);
			}
		}
	}
}


int main()
{
	int n, x, y, d, g;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		make_curve(x, y, d, g);
	}

	int cnt = 0;
	for (int y = 0; y < 100; y++)
		for (int x = 0; x < 100; x++)
			if (m[y][x] && m[y + 1][x] && m[y][x + 1] && m[y + 1][x + 1])
				cnt++;

	cout << cnt;
	return 0;
}