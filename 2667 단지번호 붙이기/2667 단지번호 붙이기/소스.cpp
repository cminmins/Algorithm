#include <iostream>
#include <algorithm>
using namespace std;
int house_num[625];
int map[25][25];
bool visit[25][25];
int num = 0;

void dfs(int x, int y, int n)
{
	if (visit[x][y] == true || map[x][y] == 0)
		return;

	visit[x][y] = true;
	num++;

	if(x+1 < n)
		dfs(x+1, y, n);
	if(x-1 >= 0)
		dfs(x-1, y, n);
	if (y - 1 >= 0)
		dfs(x, y - 1, n);
	if (y + 1 < n)
		dfs(x, y + 1, n);
}






int main()
{
	int N;
	cin >> N;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		getchar();
		for (int j = 0; j < N; j++)
			map[i][j] = getchar() - 48;
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 1 && visit[i][j] == false)
			{
				dfs(i, j, N);
				house_num[count] = num;
				count++;
			}
			num = 0;
		}
	}

	sort(house_num, house_num + count);
	cout << count << '\n';
	for (int i = 0; i < count; i++)
		cout << house_num[i] << '\n';


	return 0;
}