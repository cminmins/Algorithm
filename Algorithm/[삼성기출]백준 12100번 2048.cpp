#include <iostream>
using namespace std;

int main()
{
	int n, m, x, y, k;
	int map[20][20];
	int dice[6];
	int *nm[4], *sm[4], *wm[4], *em[4];
	nm[0] = &dice[4]; nm[1] = &dice[0]; nm[2] = &dice[1]; nm[3] = &dice[5];
	sm[0] = &dice[1]; sm[1] = &dice[0]; sm[2] = &dice[4]; sm[3] = &dice[5];
	wm[0] = &dice[3]; wm[1] = &dice[0]; wm[2] = &dice[2]; wm[3] = &dice[5];
	em[0] = &dice[2]; em[1] = &dice[0]; em[2] = &dice[3]; em[3] = &dice[5];
	int ni = 0, si = 0, wi = 0, ei = 0;

	cin >> n >> m >> x >> y >> k;

	for(int i =0; i<n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
		
	for (int i = 0; i < k; i++)
	{
		int t;
		cin >> t;
		if (t == 1 && x + 1 >= m)
			continue;
		else if (t == 2 && x - 1 <= 0)
			continue;
		else if (t == 3 && y - 1 <= 0)
			continue;
		else if (t == 4 && y + 1 >= n)
			continue;

		switch (t)
		{
		case 1:
			if (map[y][x + 1] == 0)
				map[y][x + 1] = *em[0];




			break;
		case 2:
			wm
			break;
		case 3:
			sm
			break;
		case 4:
			nm
			break;
		}



	}



	return 0;
}