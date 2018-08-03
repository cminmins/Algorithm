#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long arr[100001] = { 0 };
	int t, n, x, y;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> x >> y;
		for (int a = 0; a < 100001; a++)
			arr[a] = 0;

		for (int a = 0; a < n; a++)
			cin >> arr[a];
		sort(arr+1, arr + n);
		long sum = arr[0];

		for (int k = 0; k < x; k++)
			sum += arr[n - 1 - k];
	
		for (int k = 0; k < y; k++)
			sum -= arr[1 + k];

		cout << "#" << i << " " << sum << endl;
	}
	return 0;
}