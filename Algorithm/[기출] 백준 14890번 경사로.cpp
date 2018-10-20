#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int m[100][100];
int v[100][100];
int N, L;

bool check(int y, int x)
{
	return  (y >= 0 && y < N && x >= 0 && x < N);
}

int main()
{
	cin >> N >> L;

	int cnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> m[i][j];


	for (int y = 0; y < N; y++)
	{
		//경사로 만들기
		for (int x = 0; x < N - 1; x++)
		{
			if (m[y][x] - m[y][x + 1] == 1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y, x+i) || v[y][x + i] || (m[y][x] - m[y][x + i] != 1))
						break;
					if (i == L)
						for (int j = 1; j <= L; j++)
							v[y][x + j] = 1;
				}
			}
			else if (m[y][x] - m[y][x + 1] == -1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y, x +1- i) || v[y][x +1- i] || (m[y][x+1 - i] - m[y][x + 1] != -1))
						break;
					if (i == L)
						for (int j = 1; j <= L; j++)
							v[y][x + 1 - j] = -1;
				}
			}
		}

		bool c = true;
		// 가능여부 판단
		for (int x = 0; x < N - 1; x++)
		{
			if (m[y][x] - m[y][x + 1] == 1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y, x + i) || v[y][x + i] != 1 || (m[y][x] - m[y][x + i] != 1))
					{
						c = false;
						break;
					}
				}
			}
			else if (m[y][x] - m[y][x + 1] == -1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y, x + 1 - i) || v[y][x + 1 - i] != -1 || (m[y][x + 1 - i] - m[y][x + 1] != -1))
					{
						c = false;
						break;
					}
				}
			}
			else if (abs(m[y][x] - m[y][x + 1]) > 1)
			{
				c = false;
				break;
			}
		}
		if (c)
			cnt++;
	}
	memset(v, 0, sizeof(v));
	for (int x = 0; x < N; x++)
	{
		//경사로 만들기
		for (int y = 0; y < N - 1; y++)
		{
			if (m[y][x] - m[y+1][x] == 1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y+i, x) || v[y+i][x] || (m[y][x] - m[y+i][x] != 1))
						break;
					if (i == L)
						for (int j = 1; j <= L; j++)
							v[y+j][x] = 1;
				}
			}
			else if (m[y][x] - m[y+1][x] == -1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y+1-i, x) || v[y+1-i][x] || (m[y+1-i][x] - m[y+1][x] != -1))
						break;
					if (i == L)
						for (int j = 1; j <= L; j++)
							v[y+1-j][x] = -1;
				}
			}
		}

		bool c = true;
		// 가능여부 판단
		for (int y = 0; y < N - 1; y++)
		{
			if (m[y][x] - m[y + 1][x] == 1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y + i, x) || v[y + i][x] != 1 || (m[y][x] - m[y + i][x] != 1))
					{
						c = false;
						break;
					}
				}
			}
			else if (m[y][x] - m[y + 1][x] == -1)
			{
				for (int i = 1; i <= L; i++)
				{
					if (!check(y+1 - i, x) || v[y+1 - i][x] != -1 || (m[y+1-i][x] - m[y+1][x] != -1))
					{
						c = false;
						break;
					}
				}
			}
			else if (abs(m[y][x] - m[y + 1][x]) > 1)
			{
				c = false;
				break;
			}
		}
		if (c)
			cnt++;
	}



	cout << cnt;
	return 0;
}