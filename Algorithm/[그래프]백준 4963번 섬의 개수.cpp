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

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{

			}
		}


	}




	return 0;
}