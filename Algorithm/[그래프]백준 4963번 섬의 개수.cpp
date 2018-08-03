#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int add_x[8] = { 0,0,1,-1, -1,1,1,-1 };
int add_y[8] = { 1,-1,0,0,1,1,-1,-1 };


int main()
{
	int n, m;

	while (cin >> n >> m)
	{
		bool visit[50][50] = { 0 };
		queue<pair<int,int>> q;

		if (n == 0 && m == 0)
			break;
		int temp = 0;
		vector<vector<bool>> arr(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> temp;
				arr[i][j] = temp;
			}

		int cnt = 0;
		
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (visit[x][y] == false && arr[x][y])
				{
					int tempx = 0, tempy = 0;
					q.push(make_pair(x, y));
					while (!q.empty())
					{
						tempx = q.front().first; tempy = q.front().second; q.pop();
						if (visit[tempx][tempy] == true)
							continue;
						visit[tempx][tempy] = true;
						
						for (int a = 0; a < 8; a++)
						{
							if (tempx + add_x[a] >= 0 && tempx + add_x[a] < m && tempy + add_y[a] >= 0 && tempy + add_y[a] < n &&
								arr[tempx + add_x[a]][tempy + add_y[a]])
								q.push(make_pair(tempx + add_x[a], tempy + add_y[a]));
							
						}
					}
					cnt++;
				}
			}
		}
	


		cout << cnt << endl;
	}
	return 0;
}