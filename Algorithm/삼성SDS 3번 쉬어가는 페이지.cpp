#include <iostream>
using namespace std;

int main()
{
	int t, n, s, j, k;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		bool rest[10000] = { 0 };
		int cnt = 0;
		cin >> n >> s >> j >> k;
		for (int a = 0; a < k; a++)
		{
			int temp;
			cin >> temp;
			rest[temp] = true;
		}


		while (s <= n)
		{
			if (rest[s] == true)
				cnt++;
			s += j + 1;
		}



		cout << "#" << i << " " << cnt << endl;
	}




	return 0;
}