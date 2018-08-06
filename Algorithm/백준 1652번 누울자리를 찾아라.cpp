#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
	char arr[100][100];
	int n;
	cin >> n;	getchar();
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
			arr[j][i] = getchar();
		getchar();
	}

	int ver = 0;
	int hor = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n - 1; x++)
			if (arr[y][x] == '.' && arr[y][x + 1] == arr[y][x])
			{
				hor++;
				while (arr[y][x] == '.')
					x++;
			}

	for (int x = 0; x < n; x++)
		for (int y = 0; y < n - 1; y++)
			if (arr[y][x] == '.' && arr[y + 1][x] == arr[y][x])
			{
				ver++;
				while (arr[y][x] == '.')
					y++;
			}

	cout << hor << " " << ver;
	return 0;
}