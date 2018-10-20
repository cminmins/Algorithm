#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ty[4] = { -1, 0, 1, 0 };
int tx[4] = { 0, 1, 0, -1 };
int N, M;
int m[501][501];
bool v[501][501];

int total = 0;

void bupgu(int y, int x, int cnt, int sum)
{
	int semi_min = 1e9;
	for (int i = 0; i < 4; i++)
	{
		int ddy = y + ty[i]; int ddx = x + tx[i];
		if (ddy >= 0 && ddy < N && ddx >= 0 && ddx < M)
		{
			semi_min = min(semi_min, m[ddy][ddx]);
			sum += m[ddy][ddx];
			cnt++;
		}
	}
	if (cnt == 4)
		total = max(total, sum);
	else if (cnt == 5)
		total = max(total, sum - semi_min);
}

void func(int y, int x, int cnt, int sum)
{
	if (cnt == 4)
	{
		total = max(sum, total);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ddy = y + ty[i]; int ddx = x + tx[i];		
		if (ddy >= 0 && ddy < N && ddx >= 0 && ddx < M && v[ddy][ddx] == false)
		{
			v[ddy][ddx] = true;
			func(ddy, ddx, cnt + 1, sum + m[ddy][ddx]);
			v[ddy][ddx] = false;
		}
	}
	
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> m[y][x];

	for(int y=0; y<N; y++)
		for (int x = 0; x < M; x++)
		{
			v[y][x] = true;
			func(y, x, 1, m[y][x]);
			bupgu(y, x, 1, m[y][x]);
			v[y][x] = false;
		}
	cout << total;
	return 0;
}

