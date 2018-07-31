#include <iostream>
#include <queue>
using namespace std;
bool visit[1000][1000];
int arr[1000][1000];
int dist[1000][1000];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int main()
{
	int n, m;
	int day = 0; 
	cin >> n >> m;
	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
		{
			cin >> arr[y][x];
			dist[y][x] = -1;
		}

	queue<pair<int,int>> q;
	
	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
			if (arr[y][x] == 1)
			{
				q.push(make_pair(y, x));
				dist[y][x] = 0;
			}


	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second; q.pop();

		for (int i = 0; i < 4; i++)
		{
			int yy = y + dy[i]; int xx = x + dx[i];


			if(0 <= yy && yy <m && 0<=xx && xx <n && arr[yy][xx] == 0 && dist[yy][xx] == -1)
			{
				q.push(make_pair(yy, xx));
				//arr[yy][xx] = 1;
				dist[yy][xx] = dist[y][x] + 1;
			}
		}
	}

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++)
		{
			if (arr[y][x] == 0 && dist[y][x] == -1)
			{
				cout << -1;
				return 0;
			}
			if (day <= dist[y][x])
				day = dist[y][x];
		}
	cout << day;
	return 0;
}