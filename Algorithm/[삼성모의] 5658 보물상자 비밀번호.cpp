#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N = 0, K = 0, rot = 0;
		char nemo[28] = { 0, };
		vector<int> count;
		cin >> N >> K;
		while (getchar() != '\n');

		rot = N / 4;
		for (int i = 0; i < N; i++)
			nemo[i] = cin.get();

		for (int i = 0; i < rot; i++)
		{
			//자르기
			for (int j = 0; j < 4; j++)
			{
				int res = 0;
				for (int k = 0; k < rot; k++)
				{
					int index = (j + 1) * rot - 1 - k;
					if (nemo[index] < 65)
						res += (nemo[index] - 48) * pow(16, k);
					else
						res += (nemo[index] - 55) * pow(16, k);
				}
				count.push_back(res);
			}

			//밀기
			int temp = nemo[N - 1];
			for (int j = N - 1; j > 0; j--)
				nemo[j] = nemo[j - 1];
			nemo[0] = temp;


		}

		sort(count.begin(), count.end());

		int index = N - 1;
		//찾기
		while (K)
		{
			if (count[index] != count[index - 1])
				K--;

			if (K == 0)
				cout << "#" << test_case << " " << count[index] << endl;
			else
				index--;
		}
	}
	return 0;
}