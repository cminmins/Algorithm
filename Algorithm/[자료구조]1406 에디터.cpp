#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	vector<char> v;
	string str;
	char c, t;
	cin >> str;
	cin >> n;
	int index = str.length();
	
	for (int i = 0; i < str.length(); i++)
		v.push_back(str[i]);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &c);
		switch (c)
		{
		case 'P':
			getchar();
			scanf("%c", &t);
			if (index == v.size())
				v.push_back(t);
			else
				v.insert(v.begin() + index, t);
			index++;
			break;
		case 'B':
			if (index > 0)
			{
				v.erase(v.begin() + index - 1);
				index--;
			}
			break;
		case 'L':
			if (index > 0)
				index--;
			break;
		case 'D':
			if (index < v.size())
				index++;
			break;
		}
	}
	cout << str;
	return 0;
}