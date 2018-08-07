#include <iostream>
#include <queue>
using namespace std;

int main()
{

	int t, n;
	cin >> t;

	while (t--)
	{
		bool visit[100000];
		int arr[100000];
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			visit[i] = false;
		}

		int num = 0;
		int temp = 0;
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == false)
			{
				q.push(i);
				visit[i] = true;
				while (!q.empty())
				{
					int index = q.front(); q.pop();
					if (index == arr[index])
					{
						num += temp;
						break;
					}
					if (i == arr[index])
						break;

					if (visit[arr[index]] == false)
					{
						q.push(arr[index]);
						visit[arr[index]] = true;
						temp++;
					}
					else
						num++;
						

				}
			}

		}
		cout << num << endl;
	}
	return 0;
}