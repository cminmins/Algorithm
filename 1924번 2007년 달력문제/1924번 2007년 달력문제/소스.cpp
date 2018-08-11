#include <iostream>
using namespace std;


int main()
{
	int x, y;
	cin >> x >> y;

	for(int i = 0; i<x; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			y += 31;
		else if (i == 2)
			y += 28;
		else if(i == 4 || i == 6 || i == 9 || i == 11)
			y += 30;
	}

	if (y % 7 == 1)
		cout << "MON";
	else if (y % 7 == 2)
		cout << "TUE";
	else if (y % 7 == 3)
		cout << "WED";
	else if (y % 7 == 4)
		cout << "THU";
	else if (y % 7 == 5)
		cout << "FRI";
	else if (y % 7 == 6)
		cout << "SAT";
	else if (y % 7 == 0)
		cout << "SUN";


	return 0;
}