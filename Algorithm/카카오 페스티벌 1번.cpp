#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;


	while (t--)
	{
		int a, b;
		int sum = 0;
		cin >> a >> b;
		if (a == 1)
			sum += 5000000;
		else if (2<= a && a < 4)
			sum += 3000000;
		else if (4<= a && a < 7)
			sum += 2000000;
		else if (7<= a && a < 11)
			sum += 500000;
		else if (11<= a && a < 16)
			sum += 300000;
		else if (16 <= a && a < 22)
			sum += 100000;

		if (b == 1)
			sum += 5120000;
		else if (2 <= b && b < 4)
			sum += 2560000;
		else if (4<= b && b < 8)
			sum += 1280000;
		else if (8<= b && b < 16)
			sum += 640000;
		else if (16<= b && b < 32)
			sum += 320000;
		cout << sum << endl;
	}
	return 0;
}