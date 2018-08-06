#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int dup = n;
	int cycle = 0;

	int newn = -1;
	while (newn != n)
	{
		int sum = (dup / 10) + (dup % 10);
		newn = 10 * (dup % 10) + (sum % 10);
		dup = newn;
		cycle++;
	}
	cout << cycle;
	return 0;
}