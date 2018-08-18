#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long>v;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	int pre_count = 0;
	int cur_count = 1;
	long long min_num = 4400000000;
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] == v[i + 1])
			cur_count++;
		else
		{
			if (pre_count < cur_count)
			{
				min_num = v[i];
				pre_count = cur_count;
			}

			cur_count = 1;
		}
	}

	if (pre_count < cur_count)
		min_num = v[n - 1];


	cout << min_num;
	return 0;
}