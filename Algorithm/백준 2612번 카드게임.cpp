#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	char color[5]; int number[5];
	int ma = 0; int mi = 10;
	for (int i = 0; i < 5; i++)
	{
		cin >> color[i] >> number[i];
		mi = min(mi, number[i]);
		ma = max(ma, number[i]);
	}
	sort(number, number + 5);
	sort(color, color + 5);

	//1번 4번규칙
	if (color[0] == color[1] && color[0] == color[1] && color[0] == color[2] && color[0] == color[3] && color[0] == color[4])
	{
		if (number[0] + 1 == number[1] && number[1] + 1 == number[2] && number[2] + 1 == number[3] && number[3] + 1 == number[4])
		{
			cout << ma + 900;
			return 0;
		}
		else
		{
			cout << ma + 600;
			return 0;
		}
	}
	else
	{
		if (number[0] + 1 == number[1] && number[1] + 1 == number[2] && number[2] + 1 == number[3] && number[3] + 1 == number[4])
		{
			cout << ma + 500;
			return 0;
		}

		if ((number[0] == number[1] && number[0] == number[2] && number[0] == number[3]) || (number[1] == number[2] && number[1] == number[3] && number[1] == number[4]))
		{
			cout << number[1] + 800;
			return 0;
		}

		if ((number[0] == number[1] && number[0] == number[2] && (number[3] == number[4])))
		{
			cout << number[0] * 10 + number[3] + 700;
			return 0;
		}
		else if ((number[0] == number[1]) && (number[2] == number[3] && number[2] == number[4]))
		{
			cout << number[2] * 10 + number[0] + 700;
			return 0;
		}

		if ((number[0] == number[1] && number[0] == number[2]))
		{
			cout << number[0] + 400;
			return 0;
		}
		else if (number[1] == number[2] && number[1] == number[3])
		{
			cout << number[1] + 400;
			return 0;
		}
		else if (number[2] == number[3] && number[2] == number[4])
		{
			cout << number[2] + 400;
			return 0;
		}

		if ((number[0] == number[1] && number[2] == number[3]))
		{
			ma = max(number[0], number[2]);
			mi = min(number[0], number[2]);
			cout << ma * 10 + mi + 300;
			return 0;
		}
		else if ((number[0] == number[1] && number[3] == number[4]))
		{
			ma = max(number[0], number[3]);
			mi = min(number[0], number[3]);
			cout << ma * 10 + mi + 300;
			return 0;
		}
		else if ((number[1] == number[2] && number[3] == number[4]))
		{
			ma = max(number[1], number[3]);
			mi = min(number[1], number[3]);
			cout << ma * 10 + mi + 300;
			return 0;
		}

		if ((number[0] == number[1]))
		{
			cout << number[0] + 200;
			return 0;
		}
		else if ((number[1] == number[2]))
		{
			cout << number[1] + 200;
			return 0;
		}
		else if ((number[2] == number[3]))
		{
			cout << number[2] + 200;
			return 0;
		}
		else if ((number[3] == number[4]))
		{
			cout << number[3] + 200;
			return 0;
		}

		cout << ma + 100;
		return 0;
	}
	return 0;
}