#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n, k;
	double arr[500];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	double minm = 9999999999;
	for (int i = 0; i <= n-k; i++)
	{
		for (int j = k; j <= n- i; j++)
		{
			double var = 0;
			double temp_sum = 0;
			double  m = 0;
			for (int r = i; r < i+j; r++)
				m += arr[r];
			m /= j;
			for (int r = i; r < i + j; r++)
				temp_sum += pow((arr[r] - m), 2);
			temp_sum /= j;
			var = sqrt(temp_sum);
			minm = min(minm, var);
		}
	}
	cout.precision(11);
	cout << minm;
	return 0;
}