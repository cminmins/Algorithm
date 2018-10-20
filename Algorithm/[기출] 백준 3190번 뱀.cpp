#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int time = 1, index =1;
int y = 1, x = 1;
int N;
int m[101][101];
bool v[101][101];
queue<pair<int, int>> snake;
queue<pair<int, char>> commend;

void change_dir(char d)
{
	if (d == 'D')
		index = (4 + index + 1) % 4;
	else if (d == 'L')
		index = (4 + index - 1) % 4;
}


bool go(int sec, char d)
{
	// sec �ʸ�ŭ �ݺ�
	while(time <= sec)
	{
		y += dy[index]; x += dx[index];
		// ���� �����ų� �ڱ� ���̶� �ε����� ����
		if (y < 1 || y > N || x < 1 || x > N || v[y][x] == true)
			return false;

		//����� ������ �԰� ���� ����, ����ǥ��
		if (m[y][x] == 1)
		{
			m[y][x] = 0;
			snake.push(make_pair(y, x));
			v[y][x] = true;
		}
		// ����� ������ ���� �ڸ���, ǥ�� �����
		else if (m[y][x] == 0)
		{
			snake.push(make_pair(y, x));
			v[y][x] = true;

			int ny = snake.front().first; int nx = snake.front().second;
			v[ny][nx] = false; 
			snake.pop(); 
		}
		time++;
	}
	change_dir(d);
	return true;
}



int main()
{
	int k;
	cin >> N >> k;
	for (int i = 0; i < k; i++)
	{
		int sy, sx;
		cin >> sy >> sx;
		m[sy][sx] = 1;
	}

	int L;
	cin >> L;
	snake.push(make_pair(1, 1));
	v[1][1] = true;
	for (int i = 0; i < L; i++)
	{
		int s; char d;
		cin >> s >> d;
		commend.push(make_pair(s, d));
	}

	for (int i = 0; i < L; i++)
	{
		int s = commend.front().first; char d = commend.front().second;
		commend.pop();
		if (!go(s, d))
		{
			cout << time;
			return 0;
		}
	}
	if (!go(1e9, 's'));
		cout << time;
	return 0;
}