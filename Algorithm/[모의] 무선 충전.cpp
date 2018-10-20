#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct BC_inf
{
	int p; int c; int y; int x;
}typedef BC_inf;

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };
bool m[10][10];
queue<int> A;
queue<int> B;
vector<BC_inf> BC;


bool cmp(const BC_inf &A, const BC_inf &B)
{
	return A.p > B.p;
}

//BC와 사용자의 거리 구하기
int check_distance(int by, int bx, int y, int x)
{
	return abs(by - y) + abs(bx - x);
}

int find_max(int index, int y, int x)
{
	int bc_y, bc_x;
	for (int i = index; i < BC.size(); i++)
	{
		bc_y = BC[i].y; bc_x = BC[i].x;
		// 가능한 BC 중에서 가장 큰 BC의 인덱스값
		if (check_distance(bc_y, bc_x, y, x) <= BC[i].c)
			return i;
	}
	return -1;
}

int vattry(int y1, int x1, int y2, int x2)
{
	// 각 y,x에서 가장 큰 BC의 인덱스 찾기
	int bc1_i = find_max(0, y1, x1);
	int bc2_i = find_max(0, y2, x2);
	int max_ch = 0;
	// 둘다 존재할때
	if (bc1_i >= 0 && bc2_i >= 0)
	{
		// 해당 BC의 좌표값 받기
		int bc_y1 = BC[bc1_i].y, bc_x1 = BC[bc1_i].x;
		int bc_y2 = BC[bc2_i].y, bc_x2 = BC[bc2_i].x;

		// 두 BC가 같은 지점일때 
		int bc1_i2, bc2_i2;
		if (bc1_i == bc2_i)
		{
			// 두번째로 큰 인덱스 찾기
			if (bc1_i < BC.size())
				bc1_i2 = find_max(bc1_i + 1, y1, x1);
			if (bc1_i2 == -1)
				bc1_i2 = bc1_i;

			if (bc2_i < BC.size())
				bc2_i2 = find_max(bc2_i + 1, y2, x2);
			if (bc2_i2 == -1)
				bc2_i2 = bc2_i;

			int semi = 0;
			vector<int> ac; vector<int> bc;
			ac.push_back(bc1_i); ac.push_back(bc1_i2);
			bc.push_back(bc2_i); bc.push_back(bc2_i2);

			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
				{
					if (ac[i] == bc[j])
						semi = (BC[ac[i]].p + BC[bc[j]].p) / 2;
					else
						semi = BC[ac[i]].p + BC[bc[j]].p;

					max_ch = max(max_ch, semi);
				}
		}
		else
			max_ch = BC[bc1_i].p + BC[bc2_i].p;
	}
	else
	{
		if (bc1_i >= 0)
			max_ch += BC[bc1_i].p;
		if (bc2_i >= 0)
			max_ch += BC[bc2_i].p;
	}
	return max_ch;
}

int sum = 0;
int bfs()
{
	int ay = 0, ax = 0;
	int by = 9, bx = 9;

	m[0][0] = true; m[9][9] = true;
	int sum = vattry(0, 0, 9, 9);
	while (!A.empty() && !B.empty())
	{
		int ad = A.front(); int bd = B.front();
		A.pop(); B.pop();
		ay += dy[ad]; ax += dx[ad];
		by += dy[bd]; bx += dx[bd];
		int temp = vattry(ay, ax, by, bx);
		sum += temp;
		m[ay][ax] = true; m[by][bx] = true;
	}
	return sum;
}


int ans = 0;
int main()
{
	int t;
	cin >> t;
	for(int test = 1; test<= t; test++)
	{
		BC.clear();
		int moving, BC_cnt, temp;
		cin >> moving >> BC_cnt;
		for (int i = 0; i < moving; i++)
		{
			cin >> temp;
			A.push(temp);
		}
		for (int i = 0; i < moving; i++)
		{
			cin >> temp;
			B.push(temp);
		}
		for (int i = 0; i < BC_cnt; i++)
		{
			int y, x, c, p;
			cin >> x >> y >> c >> p;
			BC.push_back({p, c, y-1, x-1});
		}
		// P가 큰 순서대로 정리
		sort(BC.begin(), BC.end(), cmp);
		int ans = bfs();
		cout << "#" << test << " "<< ans << endl;
	}
	return 0;
}