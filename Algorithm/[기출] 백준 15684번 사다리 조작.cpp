#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N, M, H;
int m[31][11];


bool go()
{
	for (int k = 1; k <= N; k++)
	{
		int y = 1; int x = k;
		while (y <= H)
			x += m[y++][x];

		if (k != x)
			return false;
	}
	return true;
}

bool check_sel(int y, int x)
{
	if (m[y][x] == 0 && m[y][x+1] != 1)
		return true;
	else 
		return false;
}

int min_cnt = 1e9;
void func(int y, int cnt)
{
	if (go())
	{
		min_cnt = min(min_cnt, cnt);
		return;
	}

	if (cnt >= 3)
		return;

	for (int dy = y; dy <= H; dy++)
	{
		for (int dx = 1; dx < N; dx++)
		{
			if (check_sel(dy, dx))
			{
				m[dy][dx] = 1; m[dy][dx + 1] = -1;
				func(dy, cnt + 1);
				m[dy][dx] = 0; m[dy][dx + 1] = 0;
			}
		}
	}
}



int main()
{
	cin >> N >> M >> H;
	memset(m, 0, sizeof(m));
	for(int i=0; i<M; i++)
	{ 
		int y, x;
		cin >> y >> x;
		m[y][x] = 1;
		m[y][x + 1] = -1;
	}

	func(1, 0);
	if (min_cnt <= 3)
		cout << min_cnt;
	else
		cout << -1;

	return 0;	
}