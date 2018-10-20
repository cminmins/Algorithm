#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int dy[4] = { -1, 0 , 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int m[8][8];
int temp[8][8];
bool v[8][8];
int N, M;

int virus_check()
{
	int cnt = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (temp[y][x] == 0)
				cnt++;
	return cnt;
}


int max_space = 0;
queue<pair<int, int>>q;

void bfs()
{
	while (!q.empty())
	{
		int y = q.front().first; int x = q.front().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ddy = y + dy[i]; int ddx = x + dx[i];
			if (ddy < 0 || ddy >= N || ddx < 0 || ddx >= M)
				continue;

			if (temp[ddy][ddx] == 0 && !v[ddy][ddx])
			{
				v[ddy][ddx] = true;
				temp[ddy][ddx] = 2;
				q.push(make_pair(ddy, ddx));
			}
		}
	}

	int t = virus_check();
	max_space = max(t, max_space);
}

int main()
{
	cin >> N >> M;
	vector<pair<int, int>>virus_space;
	vector<pair<int, int>> e_space;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> m[y][x];
			if (m[y][x] == 2)
				virus_space.push_back(make_pair(y, x));
			else if (m[y][x] == 0)
				e_space.push_back(make_pair(y, x));
		}


	for(int z= 0; z<e_space.size(); z++)
		for(int y= 0; y<e_space.size(); y++)
			for (int x = 0; x < e_space.size(); x++)
			{
				if (z == y || z == x || x == y)
					continue;

				// 연구소 지도 초기화, 방문여부 초기화, 바이러스 위치 초기화
				
				memcpy(temp, m, sizeof(m));
				memset(v, 0, sizeof(v));
				for (int i = 0; i < virus_space.size(); i++)
					q.push(virus_space[i]);


				// 빈공간중 3개를 벽으로 만들기
				temp[e_space[z].first][e_space[z].second] = 1;
				temp[e_space[y].first][e_space[y].second] = 1;
				temp[e_space[x].first][e_space[x].second] = 1;

				bfs();
			}

	cout << max_space;
	return 0;
}