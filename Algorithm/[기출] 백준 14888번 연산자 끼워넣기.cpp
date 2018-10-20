#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> num;
vector<int> sick;
int N;
int four[4];

int oper()
{
	int sum = sick[0];
	for (int i = 1; i < sick.size(); i++)
	{
		int temp = sick[i++];

		if (temp == 0)
			sum += sick[i];
		else if (temp == 1)
			sum -= sick[i];
		else if (temp == 2)
			sum *= sick[i];
		else if(temp == 3)
		{
			if (sum < 0)
				sum = -(abs(sum) / sick[i]);
			else
				sum /= sick[i];
		}
	}
	return sum;
}


long long max_res = -1e9;
long long min_res = 1e9;
void func(int index)
{
	if (sick.size() == N + (N - 1))
	{
		long long sum = oper();
		max_res = max(max_res, sum);
		min_res = min(min_res, sum);
		return;
	}


	for (int k = 0; k < 4; k++)
	{
		if (four[k] > 0)
		{
			four[k]--;	sick.push_back(k);
			for (int i = index; i < N; i++)
			{
				sick.push_back(num[i]);
				func(i + 1);
				sick.pop_back();
			}
			four[k]++; sick.pop_back();
		}
	}
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
		cin >> four[i];

	sick.push_back(num[0]);
	func(1);
	cout << max_res << '\n' << min_res;
	return 0;
}