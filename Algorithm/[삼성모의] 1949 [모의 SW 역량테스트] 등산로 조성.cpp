#include <iostream>
#include <stack>
#include <vector>
int dx[4] = { -1, 1, 0,0 };
int dy[4] = { 0,0,1,-1 };
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;

		// 지도만들기
		vector<vector<int>> map;
		for (int i = 0; i < n; i++)
		{
			vector<int> element(n);
			map.push_back(element);
		}
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cin >> map[y][x];
		
		// 최대높이의 좌표들
		stack<pair<int, int>> xy;
		int max = 0;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				if (max < map[y][x])
					max = map[y][x];

		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				if (max == map[y][x])
					xy.push(make_pair(y, x));


		while (!xy.empty())
		{
			int ty = xy.top().first; 
			int tx = xy.top().second; xy.pop();

			for (int i = 0; i < 4; i++)
			{
				int tty = ty + dy[i];
				int ttx = tx + dx[i];

			}


		}



	}
	return 0;
}