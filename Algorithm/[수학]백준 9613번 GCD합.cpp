#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int arr[100] = { 0, };
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);

		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				int gcd = arr[i];
				int b = arr[j];
				while (	b % gcd != 0)
				{
					int temp = b;
					b = gcd;
					gcd = temp % gcd;
				}

				sum += gcd;
			}
		}
			cout << sum << endl;
	}
	return 0;
}