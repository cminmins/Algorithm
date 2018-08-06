#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
long int arr[2000000];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long int n;
	cin >> n;
	if (n == 1)
		n++;

	for (int i = n; i < 2000000; i++)
	{
		vector<long int> v;
		long int result = i;
		arr[i] = i;

		int temp = i;
		while (temp != 0)
		{
			v.push_back(temp % 10);
			temp /= 10;
		}

		for (int p = 0; p < v.size() / 2; p++)
		{
			if (v[p] != v[v.size() - p - 1])
			{
				arr[i] = 0;
				break;
			}
		}
		if (arr[i] != 0)
		{
			for (int j = 2; j <= sqrt(arr[i]); j++)
			{

				if (i % j == 0)
				{
					arr[i] = 0;
					break;
				}
			}
			if (arr[i] != 0)
			{
				cout << arr[i];
				return 0;
			}
		}
		else
			continue;
	}
	return 0;
}