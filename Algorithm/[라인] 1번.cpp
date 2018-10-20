#include <iostream>
// #include <cstdio>  // uncomment to use scanf/printf instead of cin/cout
#include <sstream>
#include <string>

using namespace std;

int main() {
	string line;
	getline(cin, line);
	stringstream ss(line);
	int total_distance = 0;
	int card = 20000;
	for (int distance; !(ss >> distance).fail(); ) {
		int add_tax = 720;

		if (distance >= 40 && distance <= 178)
		{
			add_tax += ((distance - 40) / 8) * 80;
			if ((distance - 40) % 8 > 0)
				add_tax += 80;
		}
		else if (distance < 4)
		{
			cout << card;
			return 0;
		}
		else if (distance > 178)
		{
			cout << card;
			return 0;
		}

		if (add_tax <= card)
			card -= add_tax;
		else
		{
			cout << card;
			return 0;
		}
	}
	// @todo Write your code here.
	cout << card << endl;
	return 0;
}
