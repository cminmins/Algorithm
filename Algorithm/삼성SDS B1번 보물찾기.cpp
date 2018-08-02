#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool arr[1001][1001] = {0};
//vector<int> arr[1001];
bool visit[1001] = { 0 };
int cnt = 0;
int min_time = 10001;

void dfs(int s, int d, int time)
{
		visit[s] = true;
		if (s == d)
		{
			if (min_time >= time)
				min_time = time;
		}

		for (int i = 1; i <= d; i++)
			if(arr[s][i] == true && (visit[i] == false || i ==d))
				dfs(i, d, time+1);

}



int main()
{
	int t; int n, m, k;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));

		for (int a = 0; a < m; a++)
		{
			int t1 = 0, t2 = 0;
			cin >> t1 >> t2;
			arr[t1][t2] = true;
		}

		dfs(1, n, 0);
		if(min_time > k)
			cout << "#" << i << " " << -1 << endl;
		else 
			cout << "#" << i << " " << min_time << endl;
		min_time = 10001;
	}
	return 0;
}