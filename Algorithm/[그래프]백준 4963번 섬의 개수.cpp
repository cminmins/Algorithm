#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;
		int temp = 0;
		vector<vector<bool>> arr(m, vector<bool>(n, false));
		for (vector<bool> i : arr)
			for (bool k : i)
			{
				cin >> temp;
				i[k] = temp;
			}

		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if(x-1>=0)



			}
		}




	}
	return 0;
}