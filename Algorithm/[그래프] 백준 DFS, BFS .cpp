#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;
bool arr[1001][1001];
bool visit1[1001];
bool visit2[1001];
int n, m, v;
queue<int> q;


void dfs(int start)
{
	if (visit1[start] == true)
		return;
	
	visit1[start] = true;
	cout << start << " ";

	for (int i = 1; i <= n; i++)
		if (arr[start][i] == true)
			dfs(i);

	return;
}


void bfs(int start)
{
	q.push(start);
	int temp;

	while (!q.empty())
	{
		temp = q.front(); q.pop();
		if (visit2[temp] == true)
			continue;

		visit2[temp] = true;
		cout << temp << " ";

		for (int i = 1; i <= n; i++)
			if (arr[temp][i] == true)
				q.push(i);
	}
	return;
}



int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> v;
	int temp1, temp2;

	for (int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		arr[temp1][temp2] = true;
		arr[temp2][temp1] = true;
	}

	memset(visit1, false, sizeof(visit1));
	memset(visit2, false, sizeof(visit1));


	dfs(v);
	cout << endl;
	bfs(v);


	return 0;
}

