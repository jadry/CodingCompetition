// CodingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;


int main()
{
	int t;
	int n, k;
	cin >> t;
	while (t--)
	{
		string cow;

		cin >> n >> k;
		cin >> cow;
		string p(n, '.');

		int nearestG = -k - 1;
		int nearestH = -k - 1;
		int count = 0;


		for (int i = 0; i < n; i++)
		{
			if (cow[i] == 'G' && i - nearestG > k)
			{
				// G
				if (i + k < n)
				{
					p[i + k] = 'G';
					nearestG = i + k;
					count++;
				}
				else if (p[i] == '.')
				{
					p[i] = 'G';
					nearestG = i;
					count++;
				}
				else
				{
					p[i-1] = 'G';
					nearestG = i-1;
					count++;
				}

			}
			if (cow[i] == 'H' && i - nearestH > k)
			{
				// H
				if (i + k < n)
				{
					p[i + k] = 'H';
					nearestH = i + k;
					count++;
				}
				else if (p[i] == '.')
				{
					p[i] = 'H';
					nearestH = i;
					count++;
				}
				else
				{
					p[i - 1] = 'H';
					nearestH = i - 1;
					count++;
				}
			}


		}
		cout << count << "\n" << p << "\n";


	}


}
