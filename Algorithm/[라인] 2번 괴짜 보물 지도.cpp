#include <iostream>
#include <string>
#define foward 0
#define right 1
#define back 2
#define left 3

using namespace std;
struct map
{
	string element;
	int d[4];
}typedef map;

map m[100][100];
bool v[100][100];
pair<int, int> F = make_pair(-1, 0);
pair<int, int> R = make_pair(0, 1);
pair<int, int> B = make_pair(1, 0);
pair<int, int> L = make_pair(0, -1);

int char2int(char t)
{
	if (t == 'F')
		return foward;
	else if (t == 'R')
		return right;
	else if (t == 'B')
		return back;
	else
		return left;
}

pair<int, int> int2pair(int t)
{
	if (t == foward)
		return F;
	else if (t == right)
		return R;
	else if (t == back)
		return B;
	else
		return L;
}

int pair2int(pair<int, int> dir)
{
	if (dir == F)
		return foward;
	else if (dir == L)
		return left;
	else if (dir == R)
		return right;
	else
		return back;
}


pair<int, int> check_dir(int prev_d, int next_d)
{
	pair<int, int> prev;
	pair<int, int> next;
	prev = int2pair(prev_d);
	next = int2pair(next_d);
	

	if (prev == B)
	{
		next.first *= -1;
		next.second *= -1;
	}
	else if (prev == R)
	{
		if (next == B)
			next = L;
		else if (next == L)
			next = F;
		else if (next == F)
			next = R;
		else
			next = B;
	}
	else if (prev == L)
	{
		if (next == B)
			next = R;
		else if (next == L)
			next = B;
		else if (next == F)
			next = L;
		else
			next = F;
	}
	return next;
}


int main() {
	int n;
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> m[y][x].element;

	pair<int, int> dir;
	int b = 0;
	int a = 0;
	v[0][0] = true;
	int cur_dir = back;
	while (1)
	{
		string node = m[b][a].element;
		int d = node[1] - 48;

		//b, a는 현재 좌표, cur_dir는 이전 진행 방향
		dir = check_dir(cur_dir, char2int(node[0]));
		//cur_dir는 다음 진행 방향
		cur_dir = pair2int(dir);
		if (m[b][a].d[cur_dir] == false)
		{
			v[b][a] = true;
			//현재 좌표에 방향성 체크
			m[b][a].d[cur_dir] = true;
			// b, a는 다음 좌표
			b += dir.first * d;
			a += dir.second * d;
		}
		else if (m[b][a].d[cur_dir] == true)
		{
			cout << a << " " << b;
			return 0;
		}
	}
	cout << endl;
	return 0;
}
