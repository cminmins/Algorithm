#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };

int m[51][51];
bool v[51][51];
void change_dir(int t)
{
	if (t == 0)
	{
		dy[0] = 0;
		dy[1] = 1;
		dy[2] = 0;
		dy[3] = -1;

		dx[0] = -1;
		dx[1] = 0;
		dx[2] = 1;
		dx[3] = 0;
	}
	else if (t == 1)
	{
		dy[0] = -1;
		dy[1] = 0;
		dy[2] = 1;
		dy[3] = 0;

		dx[0] = 0;
		dx[1] = -1;
		dx[2] = 0;
		dx[3] = 1;
	}
	else if (t == 2)
	{
		dy[0] = 0;
		dy[1] = -1;
		dy[2] = 0;
		dy[3] = 1;

		dx[0] = 1;
		dx[1] = 0;
		dx[2] = -1;
		dx[3] = 0;

	}
	else if (t == 3)
	{
		dy[0] = 1;
		dy[1] = 0;
		dy[2] = -1;
		dy[3] = 0;

		dx[0] = 0;
		dx[1] = 1;
		dx[2] = 0;
		dx[3] = -1;
	}
	return;
}



int main()
{
	int N, M;
	int sy, sx, d;
	cin >> N >> M >> sy >> sx >> d;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> m[y][x];


	stack<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	v[sy][sx] = true;
	change_dir(d);
	int cnt = 1;

	while (!q.empty())
	{
		int y = q.top().first; int x = q.top().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ddy = y + dy[i]; int ddx = x + dx[i];
			if (ddy < 0 || ddy >= N || ddx < 0 || ddx >= M)
				continue;

			if ((v[y+dy[0]][x+dx[0]] == true || m[y + dy[0]][x + dx[0]] == 1) && 
				(v[y + dy[1]][x + dx[1]] == true || m[y + dy[1]][x + dx[1]] == 1) && 
				(v[y + dy[2]][x + dx[2]] == true || m[y + dy[2]][x + dx[2]] == 1) && 
				(v[y + dy[3]][x + dx[3]] == true || m[y + dy[3]][x + dx[3]] == 1))
			{
				if (m[y + dy[1]][x + dx[1]] == 1)
				{
					cout << cnt;
					return 0;
				}
				q.push(make_pair(y + dy[1], x + dx[1]));
			}			
			else
			{
				if (m[ddy][ddx] == 0 && v[ddy][ddx] == false)
				{
					if (dy[i] == -1 && dx[i] == 0)
						change_dir(0);
					else if (dy[i] == 0 && dx[i] == 1)
						change_dir(1);
					else if (dy[i] == 1 && dx[i] == 0)
						change_dir(2);
					else if (dy[i] == 0 && dx[i] == -1)
						change_dir(3);
				
					v[ddy][ddx] = true;
					q.push(make_pair(ddy, ddx));
					cnt++;
					break;
				}
			}
			
		}
	}


	cout << cnt;
	return 0;
}