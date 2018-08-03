#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

struct stu
{
	string name;
	int kor;
	int math;
	int eng;
}typedef stu;
stu arr[100000];

bool cmp(const stu &p1, const stu &p2)
{
	if (p1.kor > p2.kor)
		return true;
	else if (p1.kor == p2.kor)
	{
		if (p1.eng < p2.eng)
			return true;
		else if (p1.eng == p2.eng)
		{
			if (p1.math > p2.math)
				return true;
			else if (p1.math == p2.math)
				return p1.name < p2.name;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].kor >> arr[i].eng >> arr[i].math;

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].name << '\n';

	return 0;
}