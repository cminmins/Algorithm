#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int arr[15][15] = {0, };
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		int max = 0;


		for (int i = 0; i < n-m+1; i++)
		{
			for (int j = 0; j < n-m+1; j++)
			{
				int sum = 0;
				for (int a = i; a < i + m; a++)
					for (int b = j; b < j + m; b++)
						sum += arr[a][b];
				if (max < sum)
					max = sum;
			}
		}

		cout << "#" << test_case << " " << max << endl;
	}
	return 0;
}