#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int m[9][9];
int v[9][9];
int N, M;

void right(int y, int x, int ch)
{
	for (int a = x + 1; a < M; a++)
	{
		if (m[y][a] == 6)
			return;
		if (v[y][a] == 0)
			v[y][a] = ch;
		else if (v[y][a] == ch)
			v[y][a] = 0;
	}
}

void left(int y, int x, int ch)
{
	for (int a = x - 1; a >= 0; a--)
	{
		if (m[y][a] == 6)
			return;
		if(v[y][a] == 0)
			v[y][a] = ch;
		else if (v[y][a] == ch)
			v[y][a] = 0;
	}
}

void up(int y, int x, int ch)
{
	for (int b = y - 1; b >= 0; b--)
	{
		if (m[b][x] == 6)
			return;
		if(v[b][x] == 0)
			v[b][x] = ch;
		else if (v[b][x] == ch)
			v[b][x] = 0;
	}
}

void down(int y, int x, int ch)
{
	for (int b = y + 1; b < N; b++)
	{
		if (m[b][x] == 6)
			return;
		if (v[b][x] == 0)
			v[b][x] = ch;
		else if (v[b][x] == ch)
			v[b][x] = 0;
	}
}

void first(int y, int x, int num, int ch)
{
	if (num == 0)
		up(y, x, ch);
	else if (num == 1)
		right(y, x, ch);
	else if (num == 2)
		down(y, x, ch);
	else if (num == 3)
		left(y, x, ch);
}

void second(int y, int x, int num, int ch)
{
	if (num >= 2)
		return;
	if (num == 0)
	{
		up(y, x, ch);
		down(y, x, ch);
	}
	else if (num == 1)
	{
		right(y, x, ch); 
		left(y, x, ch);
	}
}

void third(int y, int x, int num, int ch)
{
	if (num == 0)
	{
		up(y, x, ch);
		right(y, x, ch);
	}
	else if (num == 1)
	{
		right(y, x, ch);
		down(y, x, ch);
	}
	else if (num == 2)
	{
		left(y, x, ch);
		down(y, x, ch);
	}
	else if (num == 3)
	{
		up(y, x, ch);
		left(y, x, ch);
	}
}

void four(int y, int x, int num, int ch)
{
	if (num == 0)
	{
		up(y, x, ch);
		right(y, x, ch);
		left(y, x, ch);
	}
	else if (num == 1)
	{
		up(y, x, ch);
		right(y, x, ch);
		down(y, x, ch);
	}
	else if (num == 2)
	{
		left(y, x, ch);
		down(y, x, ch);
		right(y, x, ch);
	}
	else if (num == 3)
	{
		up(y, x, ch);
		left(y, x, ch);
		down(y, x, ch);
	}
}

void five(int y, int x, int num, int ch)
{
	if (num > 0)
		return;	
	up(y, x, ch);
	right(y, x, ch);
	left(y, x, ch);
	down(y, x, ch);
}


vector<pair<int, int>> cctv;

int check_see()
{
	int cnt = 0;
	for(int y=0; y<N; y++)
		for (int x = 0; x < M; x++)
			if (v[y][x] == 0)
				cnt++;
	return cnt;
}


int result = 1e9;
void func(int index)
{
	if (index == cctv.size())
	{
		int temp = check_see();
		result = min(result, temp);
		return;
	}

	for (int i = index; i < cctv.size(); i++)
	{
		int y = cctv[i].first; int x = cctv[i].second;
		for (int k = 0; k < 4; k++)
		{

			v[y][x] = i + 1;
			if (m[y][x] == 1)
				first(y, x, k, i + 1);
			else if (m[y][x] == 2)
				second(y, x, k, i + 1);
			else if (m[y][x] == 3)
				third(y, x, k, i + 1);
			else if (m[y][x] == 4)
				four(y, x, k, i + 1);
			else if (m[y][x] == 5)
				five(y, x, k, i + 1);

			func(i + 1);

			v[y][x] = 0;
			if (m[y][x] == 1)
				first(y, x, k, i + 1);
			else if (m[y][x] == 2)
				second(y, x, k, i + 1);
			else if (m[y][x] == 3)
				third(y, x, k, i + 1);
			else if (m[y][x] == 4)
				four(y, x, k, i + 1);
			else if (m[y][x] == 5)
				five(y, x, k, i + 1);

		}
	}
}



int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
		{
			cin >> m[y][x];
			if (m[y][x] == 6)
				v[y][x] = -1;
			else if (m[y][x] >= 1 && m[y][x] <= 5)
				cctv.push_back(make_pair(y, x));
		}
			
	func(0);
	cout << result;
	return 0;
}