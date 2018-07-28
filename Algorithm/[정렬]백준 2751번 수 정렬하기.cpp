#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,string> &p1, const pair<int, string> &p2)
{
	return p1.first < p2.first;
}



int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<pair<int, string>> arr;
	vector<pair<int, string>> arr2;
	for (int i=0; i<n;i++)
	{
		int x; string y;
		cin >> x >> y;
		arr.push_back(make_pair(x, y));
		arr2.push_back(make_pair(x, y));
	}
	sort(arr.begin(), arr.end(), cmp);
	stable_sort(arr2.begin(), arr2.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

	cout << "/////////////" << endl;

	for (int i = 0; i < n; i++)
		cout << arr2[i].first << " " << arr2[i].second << "\n";

	return 0;
}