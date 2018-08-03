#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];


int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr[temp]++;
	}


	for (int i = 0; i < n; i++)
	{
		for (int a = 0; a < arr[i]; a++)
			cout << i << '\n';
	}
	return 0;
}