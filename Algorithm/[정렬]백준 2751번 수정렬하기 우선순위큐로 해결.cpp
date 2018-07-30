#include <iostream>
#include <functional>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		pq.push(temp);
	}

	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		temp = pq.top(); pq.pop();
		cout << temp << '\n';
	}


	return 0;
}