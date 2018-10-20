#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 11
#define MAXT 144

using namespace std;
int m[11][11];
int match[11];
vector<pair<int, int>> man;
vector<pair<int, int>> stair;
int answer;
int n;


int distance(int man_index, int stair_index)
{
	int dy = abs(man[man_index].first - stair[stair_index].first);
	int dx = abs(man[man_index].second - stair[stair_index].second);
	return dy + dx;
}


void update()
{
	int total_min_time = 0;
	for (int si = 0; si < 2; si++)
	{
		int y = stair[si].first; int x = stair[si].second;
		int arrival_time[MAXN * 2] = { 0, };
		int current_stair[MAXT] = { 0, };


		for (int i = 0; i < man.size(); i++)
			if (match[i] == si)
				arrival_time[distance(i, si) + 1]++;


		int now_time = 0;
		for (int i = 1; i <= 20 && i <= answer; i++)
		{
			while (arrival_time[i]-- > 0)
			{
				int remain_time = m[y][x];
				for (int walk_time = i; walk_time <= MAXT; walk_time++)
				{
					if (current_stair[walk_time] < 3)
					{
						current_stair[walk_time]++;
						remain_time--;

						if (remain_time == 0)
						{
							now_time = max(now_time, walk_time + 1);
							break;
						}
					}
				}
			}
		}
		total_min_time = max(total_min_time, now_time);
	}
	answer = min(answer, total_min_time);
	return;
}


void dfs(int man_index)
{
	if (man_index == man.size())
	{
		update();
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		match[man_index] = i;
		dfs(man_index + 1);
	}
}



int main()
{
	int test;
	freopen("input.txt", "r", stdin);
	cin >> test;
	for (int i = 1; i <= test; i++)
	{
		cin >> n;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
			{
				cin >> m[y][x];
				if (m[y][x] == 1)
					man.push_back(make_pair(y, x));
				else if (m[y][x] > 1)
					stair.push_back(make_pair(y, x));
			}
				
		answer = 10000000;
		dfs(0);
		cout << "#" << i << " " << answer << endl;
		man.clear();
		stair.clear();
	}
	


	return 0;
}