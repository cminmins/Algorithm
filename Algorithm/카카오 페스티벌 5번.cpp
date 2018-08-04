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
	vector<int> singer(n + 1); // 노래의 부모 노래번호
	vector<int> singer_num(n + 1); // 가수의 노래 개수
	vector<int> singer_point(n + 1); // 가수의 평균점수
	vector<int> singer_time(n + 1); // 가수가 언제 목표점수 넘는지

	// 초기화
	for (int i = 0; i <= n; i++)
	{
		singer[i] = 0;
		singer_point[i] = 0;
		singer_num[i] = 0;
		singer_time[i] = -1;
	}

	// 부모노래에 지금 곡번호 입력
	for (int i = 2; i <= n; i++)
	{
		int temp = 0; cin >> temp;
		song[temp].push_back(i);
	}

	//지금 노래의 가수번호
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
		// 노래 주인에게 평균가중치 부여
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