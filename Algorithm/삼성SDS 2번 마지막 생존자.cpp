#include <iostream>
using namespace std;
int n;
int ck1 = 0, ck2 = 0, ck3 = 0, ck0 = 0;
int arr[100][100] = { 0 };

void whatcolor(int x, int y)
{
	if ((0 <= x && x < n) && (0 <= y && y < n))
	{
		if (arr[x][y] == 0)
			ck0 = 1;
		else if (arr[x][y] == 1)
			ck1 = 1;
		else if (arr[x][y] == 2)
			ck2 = 1;
		else if (arr[x][y] == 3)
			ck3 = 1;
	}
}


int main()
{
	int t;
	cin >> t;
	for(int c = 1; c<=t; c++)
	{
		int count = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{	
				whatcolor(i, j);
				whatcolor(i+1, j);
				whatcolor(i-1, j);
				whatcolor(i, j+1);
				whatcolor(i, j-1);
				whatcolor(i+1, j+1);
				whatcolor(i+1, j-1);
				whatcolor(i-1, j+1);
				whatcolor(i-1, j-1);

				if (ck0 == 0 && ck1 == 1 && ck2 == 1 && ck3 == 1)
					count++;
				ck0 = 0; ck1 = 0; ck2 = 0; ck3 = 0;
			}
		}
		cout << "#" << c << " " << count << endl;
	}
	return 0;
}