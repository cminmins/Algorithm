#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, C;
int m[10][10];
bool v[10][10];
vector<int> honey;
vector<int> semi_honey;


int count_honey()
{
	int sum = 0;
	for (int i = 0; i < semi_honey.size(); i++)
		sum += pow(semi_honey[i], 2);
	return sum;
}

int ans = 0;
void max_honey(int sum, int index)
{
	// C를 초과하면 종료, 아니면 최대값 갱신
	if (sum > C)
		return;
	else if (sum <= C)
	{
		int temp = count_honey();
		ans = max(ans, temp);
	}

	for (int i = index; i < honey.size(); i++)
	{
		//해당 꿀통 선택했을때
		semi_honey.push_back(honey[i]);
		max_honey(sum + honey[i], i + 1);
		semi_honey.pop_back();
		//선택안하고 갔을때
		max_honey(sum, i + 1);
	}
}


int res = 0;
void func()
{
	int person1 = 0, person2 = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (x + M - 1 < N)
			{
				for (int k = x; k < x + M; k++)
				{
					honey.push_back(m[y][k]);
					v[y][k] = true;
				}
				max_honey(0, 0);
				person1 = ans;
				ans = 0;
				honey.clear();
				semi_honey.clear();

				for (int y2 = y; y2 < N; y2++)
				{
					for (int x2 = 0; x2 < N; x2++)
					{
						if (x2 + M - 1 < N && v[y2][x2 + M - 1] == false && v[y2][x2] == false)
						{
							for (int k = x2; k < x2 + M; k++)
							{
								honey.push_back(m[y2][k]);
								v[y2][k] = true;
							}
							max_honey(0, 0);
							person2 = ans;
							ans = 0;
							honey.clear();
							semi_honey.clear();

							res = max(res, person1 + person2);
							for (int k = x2; k < x2 + M; k++)
								v[y2][k] = false;

						}
					}
				}
				for (int k = x; k < x + M; k++)
					v[y][k] = false;
			}
		}
	}
}



int main()
{
	int test;
	cin >> test;
	for (int t = 1; t <= test; t++)
	{
		ans = 0;
		res = 0;
		cin >> N >> M >> C;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> m[y][x];


		func();
		cout << "#" << t << " " << res << endl;
	}
	return 0;
}