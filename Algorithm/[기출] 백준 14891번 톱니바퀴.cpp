#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int topni[5][8];
int met[100][2];

void swaparr(int* t, int dir)
{
	if (dir == 1)
	{
		int temp = t[7];
		for (int i = 7; i > 0; i--)
			t[i] = t[i - 1];
		t[0] = temp;
	}
	else if (dir == -1)
	{
		int temp = t[0];
		for (int i = 0; i < 7; i++)
			t[i] = t[i + 1];
		t[7] = temp;
	}
}

void turning_right(int num, int dir)
{
	if (num >= 4)
		return;

	if (topni[num][2] != topni[num + 1][6])
	{
		turning_right(num + 1, -dir);
		swaparr(topni[num + 1], -dir);
	}
}

void turning_left(int num, int dir)
{
	if (num <= 0)
		return;

	if (topni[num - 1][2] != topni[num][6])
	{
		turning_left(num - 1, -dir);
		swaparr(topni[num - 1], -dir);
	}
}

void change_top(int num, int dir)
{
	if(num <= 3)
		if (topni[num][2] != topni[num + 1][6])
		{
			turning_right(num + 1, -dir);
			swaparr(topni[num + 1], -dir);
		}
	if(num >= 2)
		if (topni[num - 1][2] != topni[num][6])
		{
			turning_left(num - 1, -dir);
			swaparr(topni[num - 1], -dir);
		}
	swaparr(topni[num], dir);
}

int sum_mig()
{
	return topni[1][0] + topni[2][0] * 2 + topni[3][0] * 4 + topni[4][0] * 8;
}

int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
			topni[i][j] = cin.get() - 48;
		getchar();
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> met[i][0] >> met[i][1];

	for (int i = 0; i < n; i++)
		change_top(met[i][0], met[i][1]);

	int sum = sum_mig();
	cout << sum;
	return 0;
}