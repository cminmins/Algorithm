#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { 0, 1, 0, -1};
int dx[4] = { 1, 0, -1, 0};
int N, M;
char m[10][10];
bool v[10][10][10][10];

struct rb
{
	int cnt; int ry; int rx; int by; int bx;
}typedef rb;
queue<rb> q;


int ans = 1e9;
void bfs()
{
	while (!q.empty())
	{
		int ry = q.front().ry; int rx = q.front().rx;
		int by = q.front().by; int bx = q.front().bx;
		int cnt = q.front().cnt;
		q.pop();

		if (cnt >= 11)
		{
			ans = -1;
			return;
		}
		
		if (m[ry][rx] == 'O' && m[by][bx] != 'O')
		{
			ans = cnt;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int rry = ry; int rrx = rx; int bby = by; int bbx = bx;

			// 레드 벽까지 굴리기, 출구만나면 탈출
			while (1)
			{
				if (m[rry + dy[i]][rrx + dx[i]] == '#' || m[rry][rrx] == 'O')
					break;
				rry += dy[i]; rrx += dx[i];
			}

			// 블루 벽까지 굴리기, 출구만나면 탈출
			while (1)
			{
				if (m[bby + dy[i]][bbx + dx[i]] == '#' || m[bby][bbx] == 'O')
					break;
				bby += dy[i]; bbx += dx[i];
			}

			// 굴린 장소가 겹칠때
			if (rry == bby && rrx == bbx)
			{
				// 블루가 출구 만났으면 
				if (m[bby][bbx] == 'O')
					continue;
				// 이동거리 비교
				if (abs(rry - ry) + abs(rrx - rx) > abs(bby - by) + abs(bbx - bx))
				{
					rry -= dy[i]; rrx -= dx[i];
				}
				else
				{
					bby -= dy[i]; bbx -= dx[i];
				}

			}

			if (v[rry][rrx][bby][bbx] == 0)
			{
				v[rry][rrx][bby][bbx] = 1;
				q.push({ cnt + 1, rry, rrx, bby, bbx });
			}
		}

	}
	ans = -1;
	return;
}

int main()
{
	cin >> N >> M;
	int ry, rx, by, bx;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> m[y][x];
			if (m[y][x] == 'R')
			{
				ry = y; rx = x;
				m[y][x] = '.';
			}
			else if (m[y][x] == 'B')
			{
				by = y; bx = x;
				m[y][x] = '.';
			}
		}

	q.push({ 0, ry,rx,by,bx });
	v[ry][rx][by][bx] = 1;
	bfs();
	cout << ans;
	return 0;
}