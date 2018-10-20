#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char arr[15];
int l, c;
//int moum;
//int jaum;
vector<char> v;

void dfs(int index, int moum, int jaum)
{
	if (v.size() == l)
	{
		if (moum >= 1 && jaum >=2)
		{
			for (int i = 0; i < l; i++)
				cout << v[i];
			cout << endl;
		}
		return;
	}
	for (int i = index; i < c; i++)
	{
		v.push_back(arr[i]);
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'i' || arr[i] == 'u')
			moum++;
		else
			jaum++;
		dfs(i + 1);
		v.pop_back();
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'o' || arr[i] == 'i' || arr[i] == 'u')
			moum--;
		else
			jaum--;
	}
}



int main()
{
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> arr[i];
	sort(arr, arr + c);

	dfs(0, 0, 0);
	return 0;
}