#include <bits/stdc++.h>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;

	long long T;


	cin >> N >> T;

	long long eat = 0;

	long long d=0, b=0;

	long long lastDay = 0;

	for (int i = 0; i < N; i++)
	{
		
		cin >> d >> b;


		if (T < d)
			break;

		
		if (d >= lastDay )
		{
			if (b >= (T - d + 1))
			{
				eat += (T - d + 1);
				break;
			}

			eat += b;
			lastDay = d + b;
		}
		else
		{
			if (b >= (T - lastDay + 1))
			{
				eat += (T - lastDay + 1);
				break;
			}

			eat += b;
			lastDay = lastDay + b;
		}
	}

	cout << eat;

	return 0;


}