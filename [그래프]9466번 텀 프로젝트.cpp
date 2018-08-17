#include <iostream>
#include <queue>
using namespace std;

int main()
{

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		int arr[100000] = { 0, };
		bool visit[100000] = { false, };
		queue<int> q;
		int total = n;

		for (int i =1; i<=n; i++)
			cin >> arr[i];

		for (int i = 1; i <= n; i++)
		{
			int count = 0;
			for (int j = 0; j <= n; j++)
				visit[j] = false;

			int start = i;
			q.push(i);
			visit[i] = true;
			count++;

			while (!q.empty())
			{
				int cur = q.front(); q.pop();
				visit[cur] = true;
				int des = arr[cur];

				if (cur == des)
					break;
				else if (start == des)
				{
					total -= count;
					count = 0;
					break;
				}
				else if (visit[des] == false)
					q.push(des);
			}
		}
		cout << total << endl;
	}
	return 0;
}