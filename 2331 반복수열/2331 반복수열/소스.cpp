#include <iostream>
#include <cmath>
using namespace std;

int next(int a, int p)
{
	int temp = 0;
	while (0 < a)
	{
		temp += pow(a % 10, p);
		a /= 10;
	}
	return temp;
}



int main()
{
	bool check[100000] = { 0 };
	int d[100000] = { 0 };


	int P;
	cin >> d[1] >> P;
	int temp = d[1];
	int n = 1;

	while (!check[d[n]])
	{
		check[d[n]] = true;
		d[n + 1] = next(d[n], P);
		n++;
	}
	
	int i = 1; int count = 0;
	while (d[i++] != d[n])
		count++;
	
	cout << count;

	return 0;
}