#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[21][21];
bool v[21];
int gap = 1e9;

int sum_status()
{
	int sum = 0;
	for(int i=1; i<=N; i++)
		for (int j = i + 1; j <= N; j++)
		{
			if (v[i] == v[j] && v[i] == true)
			{
				sum += arr[i][j];
				sum += arr[j][i];
			}
			else if (v[i] == v[j] && v[i] == false)
			{
				sum -= arr[i][j];
				sum -= arr[j][i];
			}
		}
	return abs(sum);
}


void dfs(int cnt, int index)
{
	if (cnt == N / 2)
	{
		gap = min(gap, sum_status());
		return;
	}

	for (int i = index; i <= N; i++)
	{
		v[i] = true;
		dfs(cnt + 1, i + 1);
		v[i] = false;
	}
}


int main()
{
	cin >> N;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> arr[y][x];

	dfs(0, 1);
	cout << gap;
	return 0;
}