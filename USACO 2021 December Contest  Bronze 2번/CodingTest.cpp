#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	
	cin >> N;


	vector<int> p(N);
	int t;

	for (int i = 0; i < N; i++)
		cin >> p[i];
	for (int i = 0; i < N; i++)
	{
		cin >> t;

		p[i] -= t;

	}


	int count = 0;
	int step;
	for (int i = 0; i < N; )
	{
		if (p[i] == 0)
		{
			i++;
			continue;
		}

		if (p[i] > 0)
			step = -1;
		else
			step = 1;

		for (int j = i; j < N; j++)
		{
			if (p[j] == 0)
				break;
			if (step * p[j] > 0) //0이거나 부호가 다르면 정지
				break;

			if (j == i && j < N - 1 && p[j + 1] == 0)
			{
				count += (fabs(p[i]) -1 );
				p[j] = 0;
				break;
			}

			p[j] += step;

		}
		count ++;

	}
	cout << count; 

}
