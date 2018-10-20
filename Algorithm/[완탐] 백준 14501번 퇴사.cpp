#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[16][2];
int n;
int price;
int ans;
vector<int> v;

void dfs(int index)
{
	for (int i = index; i <= n; i++)
	{
		if (i + a[i][0] <= n + 1)
		{
			price += a[i][1];
			ans = max(ans, price);
			dfs(i + a[i][0]);
			price -= a[i][1];
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i][0] >> a[i][1];

	dfs(1);
	cout << ans;
	return 0;
}