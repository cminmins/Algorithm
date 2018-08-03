#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	int N, M;
	int x1, y1;
	int x2, y2;

	cin >> T;

	for(int i= 1; i <=T; i++)
	{
		cin >> N >> M >> x1 >> y1 >> x2 >> y2;
		int rx = 0, ry = 0;
		int temp1 = 0;
		int temp2 = 0;
		 
		if (x1 < x2)
			swap(x1, x2);
		if (y1 < y2)
			swap(y1, y2);

		temp1 = x1 - x2;
		temp2 = N + x2 - x1;

		if (temp1 >= temp2)
			rx = temp2;
		else
			rx = temp1;

		temp1 = y1 - y2;
		temp2 = M + y2 - y1;

		if (temp1 >= temp2)
			ry = temp2;
		else
			ry = temp1;


		cout << "#" << i << " " << rx + ry << endl;
	}



	return 0;
}