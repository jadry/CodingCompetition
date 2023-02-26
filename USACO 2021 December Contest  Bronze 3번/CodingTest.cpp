#include <bits/stdc++.h>
using namespace std;


string m[51] ;
int N, K;
int cnt = 0;




void go(int dir, bool right, bool down , int x, int y)
{
	if (dir > K)
		return;
	if (x >= N || y >= N)
		return;

	if (x == N - 1 && y == N - 1)
	{
		cnt++;
		return;

	}

	if (m[y][x] != '.')
		return;

	if (x == 0 && y == 0) //first
	{
		go(dir, true, false, 1, 0);
		go(dir, false, true, 0, 1);
		return;
	}

	if (right)
	{
		go(dir, true, false, x + 1, y);
		go(dir + 1, false, true, x, y + 1);
		return;
	}
	else if (down)
	{
		go(dir + 1, true, false, x + 1, y);
		go(dir, false, true, x, y + 1);
		return;
	}
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	int T;

	cin >> T;

	while (T--)
	{
		cin >> N >> K;

		for (int i = 0; i < N; i++)
			cin >> m[i];

		cnt = 0;

		go(0, false , false, 0 , 0);

		cout << cnt << "\n";
	}


	return 0;


}