#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k, j;
	cin >> n >> k >> j;
	vector<vector<int>> song(n+1);
	vector<int> singer(n + 1); // �뷡�� �θ� �뷡��ȣ
	vector<int> singer_num(n + 1); // ������ �뷡 ����
	vector<int> singer_point(n + 1); // ������ �������
	vector<int> singer_time(n + 1); // ������ ���� ��ǥ���� �Ѵ���

	// �ʱ�ȭ
	for (int i = 0; i <= n; i++)
	{
		singer[i] = 0;
		singer_point[i] = 0;
		singer_num[i] = 0;
		singer_time[i] = -1;
	}

	// �θ�뷡�� ���� ���ȣ �Է�
	for (int i = 2; i <= n; i++)
	{
		int temp = 0; cin >> temp;
		song[temp].push_back(i);
	}

	//���� �뷡�� ������ȣ
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		cin >> temp;
		singer[i] = temp;
		singer_num[temp]++;
	}
	
	for (int i = 1; i <= k; i++)
	{
		int time, sub, point;
		int number = 1;
		cin >> time >> sub >> point;
		queue<int> q;
		queue<int> check;
		q.push(sub); check.push(sub);
		while (!q.empty())
		{
			int index = q.front(); q.pop();
			for (int a = 0; a<song[index].size(); a++)
			{
				number++;
				if(song[song[index][a]].size() > 0)
					q.push(song[index][a]); check.push(song[index][a]);
			}
		}
		int avg = point / number;
		// �뷡 ���ο��� ��հ���ġ �ο�
		while (!check.empty())
		{
			int index = check.front(); check.pop();
			singer_point[singer[index]] += avg;
		}

		for (int i = 1; i <= n; i++)
		{
			if(singer_num[i] != 0)
				if((singer_point[i] / singer_num[i]) >= j && singer_time[i] == -1)
					singer_time[i] = time;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << singer_time[singer[i]] << '\n';
	return 0;
}