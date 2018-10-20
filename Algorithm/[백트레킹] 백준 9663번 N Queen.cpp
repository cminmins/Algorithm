#include <iostream>
using namespace std;
bool v[15][15];
int n;
int ans = 0;


bool check(int y, int x)
{
	//3������ Ȯ���ϱ� y,x���� y������ ��, ���� �밢����, ������ �밢�� ��
	// y�� ��
	for (int b = 0; b < n; b++)
	{
		if (b == y) 
			continue;
		if (v[b][x])
			return false;
	}

	//���� �밢�� ��
	int b = y - 1;
	int a = x - 1;
	while (b >= 0 && a >= 0)
	{
		if (v[b][a] == true)
			return false;
		b -= 1;
		a -= 1;
	}

	//������ �밢�� ��
	b = y - 1;
	a = x + 1;
	while (b >= 0 && a < n)
	{
		if (v[b][a] == true)
			return false;
		b -= 1;
		a += 1;
	}
	
	return true;
}


void dfs(int y)
{
	if (y == n)
		ans += 1;

	for (int dx = 0; dx < n; dx++)
	{
		v[y][dx] = true;
		if (check(y, dx))
			dfs(y + 1);
		v[y][dx] = false;
	}
	
}



int main()
{
	cin >> n;
	dfs(0);
	cout << ans << endl;
	return 0;
}