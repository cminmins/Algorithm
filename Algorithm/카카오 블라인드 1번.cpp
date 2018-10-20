#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++)
	{
		stringstream ss(record[i]);
		string command, uid, name;
		ss >> command;

		if (command == "Enter")
		{
			ss >> uid >> name;
			m[uid] = name;
		}
		else if (command == "Change")
		{
			ss >> uid >> name;
			m[uid] = name;
		}
	}

	for (int i = 0; i < record.size(); i++)
	{
		stringstream ss(record[i]);
		string command, uid, name;
		ss >> command;

		if (command == "Enter")
		{
			ss >> uid >> name;
			name = m[uid];
			answer.push_back(name + "님이 들어왔습니다.");
		}
		else if (command == "Leave")
		{
			ss >> uid >> name;
			name = m[uid];
			answer.push_back(name + "님이 나갔습니다.");
		}
	}
	return answer;
}


int main()
{
	vector<string> r = { "Enter uid1234 Muzi", "Enter uid4567 Prodo" ,"Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	solution(r);

	return 0;
}