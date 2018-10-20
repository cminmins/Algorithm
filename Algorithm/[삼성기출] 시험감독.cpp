#include <iostream>
using namespace std;
int s[1000001];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int a, b;
	cin >> a >> b;

	int a_count = n;
	long long b_count = 0;

	for (int i = 0; i < n; i++)
	{
		if(s[i] - a > 0)
			b_count += (s[i] - a) / b;
		if ((s[i] - a) % b > 0)
			b_count++;
	}
		
	cout << a_count + b_count;
	return 0;
}