#include <string>
#include <iostream>
#include <vector>

using namespace std;
int next_index[200000] = { 0, };

int solution(vector<int> food_times, long long k) {
	int answer = 0;
	int cur = 0;
	int prev = food_times.size()-1;

	for (int i = 0; i < food_times.size(); i++)
		next_index[i] = i + 1;
	next_index[food_times.size() - 1] = 0;


	for (int i = 0; i < k; i++)
	{
		if (food_times[cur] > 0)
			food_times[cur]--;

		if (food_times[cur] > 0)
		{
			prev = cur;
			next_index[prev] = next_index[cur];
		}
		else if (food_times[cur] == 0)
			next_index[prev] = next_index[cur];

		cur = next_index[cur];
	}

	int sum = 0;
	for (int i = 0; i<food_times.size(); i++)
		sum += food_times[i];

	if (sum > 0)
		return cur + 1;
	else if (sum == 0)
		return -1;
}

int main()
{
	vector<int> food_times = { 5,1,1,1,5 };
	long long k = 15;
	cout << solution(food_times, k) << endl;
	//for (int i = 0; i < 10; i++)
	//	cout << solution(food_times, i) << endl;
	return 0;
}