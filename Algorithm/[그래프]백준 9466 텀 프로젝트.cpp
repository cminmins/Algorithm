#include <iostream>
#include <queue>
using namespace std;
int arr[100000];
int start[100000];
int dis[100000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			arr[i] = 0;
			start[i] = 0;
			dis[i] = 0;
		}

		queue<int> q;
		int total = 0;

		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++)
		{
			int count = 1;
			if (dis[i] == 0)
			{
				start[i] = i;
				q.push(i);
				dis[i] = 1;

				while (!q.empty())
				{
					int cur = q.front(); q.pop();
					int des = arr[cur];
					if (dis[des] != 0)
					{
						if (start[i] != start[des])
							break;
						else if(start[i] == start[des])
						{
							total += count - dis[des] + 1;
							break;
						}
					}
					else if(dis[des] == 0)
					{
						dis[des] = dis[cur] + 1;
						start[des] = start[i];
						q.push(des);
						count++;
					}
				}				
			}
		}
		cout << n - total << '\n';
	}
	return 0;
}