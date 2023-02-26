#include <bits/stdc++.h>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;

	long long T;


	cin >> N >> T;

	long long stock = 0;
	long long eat = 0;

	long long preD=0, preB = 0;
	long long d=0, b=0;

	long long eatDay = 0;

	for (int i = 0; i < N; i++)
	{
		
		cin >> d >> b;


		if (T < d)
			break;

		stock += b;

		if (d >= eatDay )
		{
			if (stock >= (T - d + 1))
			{
				eat += (T - d + 1);
				break;
			}

			eat += stock;
			eatDay = d + stock;
		}
		else
		{
			if (stock >= (T - eatDay + 1))
			{
				eat += (T - eatDay + 1);
				break;
			}

			eat += stock;
			eatDay = eatDay + stock;
		}

		stock = 0;
	}

	cout << eat;

	return 0;


}