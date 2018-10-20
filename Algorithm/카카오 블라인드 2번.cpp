#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
bool cmp(const pair<float, int> &p1, const pair<float, int> &p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	else
		return p1.first > p2.first;
}
float now[200000] = { 0, };
float pass[200000] = { 0, };


vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	for (int i = 0; i<stages.size(); i++)
	{
		for (int j = 0; j<stages[i]; j++)
			pass[j] += 1;
		now[stages[i] - 1] += 1;
	}
	vector<pair<float, int>> result;

	float tem = 0;
	for (int i = 0; i<N; i++)
	{
		if (pass[i] == 0)
			tem = 0;
		else
			tem = now[i] / pass[i];
		result.push_back(make_pair(tem, i));
	}
	sort(result.begin(), result.end(), cmp);

	for (int i = 0; i<N; i++)
		answer.push_back(result[i].second + 1);

	return answer;
}