#include <iostream>
#include <queue>
using namespace std;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int arr[100][100];
int num[100][100];
bool visit[100][100];
int d[100][100];

int main()
{
	int n;
	cin >> n;

	queue<pair<int, int>> q;
	queue<pair<int, int>> rq;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			num[i][j] = -1;
			d[i][j] = -1;
		}
	
	// 섬 번호 매기기
	int count = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				num[i][j] = count++;
				while (!q.empty())
				{
					int y = q.front().first; int x = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++)
					{
						int ddx = x + dx[i]; int ddy = y + dy[i];
						if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < n&& arr[ddy][ddx] == 1 && visit[ddy][ddx] == false)
						{
							visit[ddy][ddx] = true;
							num[ddy][ddx] = num[y][x];
							q.push(make_pair(ddy, ddx));
						}
					}
				}
			}
		}

	}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] == 1)
			{
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}

	
	while (!q.empty())
	{
		int y = q.front().first; int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ddx = x + dx[i]; int ddy = y + dy[i];
			if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < n && visit[ddy][ddx] == false)
			{
				if (d[ddy][ddx] == -1)
				{
					d[ddy][ddx] = d[y][x] + 1;
					num[ddy][ddx] = num[y][x];
					q.push(make_pair(ddy, ddx));
				}
			}
		}
	}

	int min = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 4; k++)
			{
				int ddx = j + dx[k]; int ddy = i + dy[k];
				if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < n && num[ddy][ddx] != num[i][j])
					if (min == -1 || min > d[ddy][ddx] + d[i][j])
						min = d[ddy][ddx] + d[i][j];
			}



	cout << min;
	return 0;
}