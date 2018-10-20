#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;


	long double temp = 1;
	long int gisu = 0;
	for (int i = 1; i <= m; i++)
	{
		temp *= n - (i - 1);
		temp /= i;

		while (temp > 9)
		{
			temp /= 10;
			gisu++;
		}
	}


	cout << temp * pow(10, gisu);
	return 0;
}