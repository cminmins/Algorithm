#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
// 먼지 번호, 가중치
char m[21][21];
int d[21][21];
bool v[21][21];
int w, h;

int dust = 1;



bool flag;
int dis[11][11];

pair<int, int> member[11];
void bfs(int y, int x, int s)
{
	for (int b = 0; b < h; b++)
		for (int a = 0; a < w; a++)
			d[b][a] = -1;

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	d[y][x] = 0;
	v[y][x] = true;

	while (!q.empty())
	{
		int y = q.front().first; int x = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ddy = y + dy[i]; int ddx = x + dx[i];
			//기본조건
			if (!(ddy >= 0 && ddy < h && ddx >= 0 && ddx < w))
				continue;

			if (m[ddy][ddx] != 'x' && d[ddy][ddx] == -1)
			{
				v[ddy][ddx] = true;
				q.push(make_pair(ddy, ddx));
				d[ddy][ddx] = d[y][x] + 1;
			}
			
		}
	}


	for (int i = 0; i < dust; i++)
	{
		dis[s][i] = d[member[i].first][member[i].second];
		dis[i][s] = dis[s][i];
	}
	return;
}



int min_depth = 1e9;
bool dfs_v[11];
int ccount = 0;
void dfs(int index, int distance, int cnt)
{
	//ccount++;
	if (cnt == dust)
	{
		min_depth = min(distance, min_depth);
		flag = true;
		return;
	}

	for (int i = 0; i < dust; i++) 
	{
		if (!dfs_v[i])
		{
			if (dis[index][i] == 0) continue;
			dfs_v[i] = true;
			if(dis[index][i] != -1 && distance + dis[index][i] < min_depth)
				dfs(i, distance + dis[index][i], cnt + 1);
			dfs_v[i] = false;
		}
	}
}


int main()
{
	while (1)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			return 0;

		dust = 1;
		min_depth = 1e9;
		// 먼지는 1...2.. 3..  청소기는 0, 가구는 -1
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
			{
				cin >> m[y][x];
				if (m[y][x] == '*')
					member[dust++] = make_pair(y,x);
				else if (m[y][x] == 'o')
					member[0] = make_pair(y, x);
			}
		
		for (int i = 0; i < dust; i++)
		{
			bfs(member[i].first, member[i].second, i);
			memset(v, 0, sizeof(v));
			memset(d, 0, sizeof(d));
		}

		dfs_v[0] = true;
		dfs(0, 0, 1);
		if (!flag) min_depth = -1;
		cout << min_depth << endl;

		flag = false;
		memset(m, 0, sizeof(m));
		memset(dis, 0, sizeof(dis));
		memset(dfs_v, 0, sizeof(dfs_v));

		//cout << "DFS 횟수 : " << ccount << endl;
	}
	return 0;
}
