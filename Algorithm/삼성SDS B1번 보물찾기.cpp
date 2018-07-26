#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
queue<int> bfs_queue;
bool visit[1001] = { false };
bool map[1001][1001] = { false };
int dist[1001] = { -1 };

int main()
{
	int t, n, m, k;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k;
		memset(visit, 0, sizeof(visit));
		memset(map, 0, sizeof(map));
		for (int k = 0; k <= n; k++)
			dist[k] = -1;

		for (int a = 0; a < m; a++)
		{
			int temp1, temp2;
			cin >> temp1 >> temp2;
			map[temp1][temp2] = true;
		}

		bfs_queue.push(1);
		dist[0] = 0;
		dist[1] = 0;
		while (!bfs_queue.empty())
		{
			int node = bfs_queue.front(); bfs_queue.pop();
			if (visit[node] == false)
			{
				visit[node] = true;
				for (int b = 1; b <= n; b++)
					if (map[node][b] == true && visit[b] == false)
					{
						bfs_queue.push(b);
						if(dist[b] == -1)
							dist[b] = dist[node] + 1;
					}
			}
		}
		if(dist[n] > k)
			cout << "#" << i << " " << -1 << endl;
		else
			cout << "#" << i << " " << dist[n] << endl;
	}




	return 0;
}