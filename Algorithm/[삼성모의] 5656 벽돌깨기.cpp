#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, w, h;
		cin >> n >> w >> h;

		//블럭생성
		vector<vector<int>> block;
		for (int i = 0; i < w; i++)
		{
			vector<int> elem(h);
			block.push_back(elem);
		}
		for (int i = h; i > 0; i--)
			for (int j = 0; j < w; j++)
			{
				int temp;
				cin >> temp;
				if (temp == 0)
					block[j].pop_back();
				else
					block[j][i - 1] = temp;
			}
		
		
		int index = n;
		int aim = block[index].back() - 1;
		block[index].pop_back();
		while (aim > 0)
		{
			if (block[index].size() > aim)
			{
				for (int i = 0; i < aim; i++)
				{

				}
			}



		}
		

		cout << endl;



	}
	return 0;
}