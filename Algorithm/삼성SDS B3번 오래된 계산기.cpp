#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		int n = 0;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int a = 0; a < n; a++)
		{
			long long temp = 0;
			cin >> temp;
			pq.push(temp);
		}

		long long sum = 0;
		while (1)
		{
			long long temp = 0;
			temp += pq.top();
			pq.pop();
			temp += pq.top();
			pq.pop();

			sum += temp;
			pq.push(temp);
			if (pq.size() == 1)
				break;
		}
		cout << "#" << i << " " << sum << endl;
	}
	return 0;
}