#include <bits/stdc++.h>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N, K;

		cin >> N;
		vector<string> want(N);
		for (int i = 0; i < N; i++)
			cin >> want[i];

		cin >> K;
		vector<vector<string>> stamp(4, vector<string>(K));
		for (int i = 0; i < K; i++)
			cin >> stamp[0][i];


		stamp[1] = stamp[0];
		stamp[2] = stamp[0];
		stamp[3] = stamp[0];

		//90
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				stamp[1][j][K - i - 1] = stamp[0][i][j];

		//180
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				stamp[2][j][K - i - 1] = stamp[1][i][j];

		//270
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				stamp[3][j][K - i - 1] = stamp[2][i][j];

		for (int i = 0; i < N - K + 1; i++)
			for (int j = 0; j < N - K + 1; j++)
				for (int r = 0; r < 4; r++) //rotate
				{
					bool next = false;
					for (int y = 0; y < K; y++)
					{
						for (int x = 0; x < K; x++)
						{

							if (stamp[r][y][x] == '*' && want[i + y][j + x] == '.')
							{
								next = true;
								break;
							}
						}
						if (next)
							break;

					}
					if (next)
						continue;

					for (int y = 0; y < K; y++)
						for (int x = 0; x < K; x++)
						{
							if (stamp[r][y][x] == '*')
								want[i + y][j + x] = 'O'; // stamp mark
						}
				}

		bool isNo = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (want[i][j] == '*')
				{
					isNo = true;
					break;
				}
			}
			if (isNo)
				break;

		}

		if( isNo)
			cout << "NO\n";
		else
			cout << "YES\n";

	}

	
	return 0;


}