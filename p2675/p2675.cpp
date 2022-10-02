#include <bits/stdc++.h>

// https://www.acmicpc.net/problem/2675

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int times;
	int count;
	string unrep;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
		string answer = "";
		cin >> count >> unrep;
		for (int x = 0; x < size(unrep); x++)
		{
			string stuff(count, unrep[x]);
			answer = answer + stuff;
		}
		cout << answer << '\n';
	}

}