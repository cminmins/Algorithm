#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int m[51][51];
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> allchic;
int result = 1e9;

void check_dis()
{
	int total_min = 0;
	//모든 고객에서 최단 치킨거리 구하기
	for (int i = 0; i < house.size(); i++)
	{
		int sub_min = 1e9;
		int y = house[i].first; int x = house[i].second;
		// i번째 고객에서 가장 가까운 치킨집 찾기
		for (int j = 0; j < chicken.size(); j++)
		{
			int dis = abs(y - chicken[j].first) + abs(x - chicken[j].second);
			sub_min = min(dis, sub_min);
		}
		total_min += sub_min;
	}
	result = min(total_min, result);
}


void func(int index, int cnt)
{
	if (cnt == M)
	{
		check_dis();
		return;
	}

	for (int i = index; i < allchic.size(); i++)
	{
		chicken.push_back(make_pair(allchic[i].first, allchic[i].second));
		func(i + 1, cnt + 1);
		chicken.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			cin >> m[y][x];
			if (m[y][x] == 1)
				house.push_back(make_pair(y, x));
			else if (m[y][x] == 2)
				allchic.push_back(make_pair(y, x));
		}

	func(0, 0);
	cout << result;
	return 0;
}